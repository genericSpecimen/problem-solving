# Synchronization Tools

## Race condition
* Concurrent or parallel execution can contribute to issues involving the integrity of data shared by several processes.

* The concurrent execution of higher level stmts like “count++” and “count--” is equivalent to a sequential execution in which the lower-level statements are interleaved in some arbitrary order (but the order within each high-level stmt is preserved)

* **Race condition**: when several processes access and manipulate the same data concurrently and the outcome of the execution depends on the particular order in which the accesses takes place.
    * To guard against race conditions we need to ensure that only one process at a time can be manipulating the variable count. To make such a guarantee, we require that the processes be synchronized in some way.
    * multi-threaded applications running on multiple cores: several threads sharing data are running in parallel on diff processing cores.
    * eg: modifying kernel DS - list of open files when two processes open files simultaneously; value of the next available pid when assigning pids to two child processes created simultaneously; memory allocation DS; process lists, etc.

## Critical Section Problem
* **Critical section**: section of code in which the process may be accessing and updating data shared with at least one other process.
    * no two processes should be executing in their critical sections at the same time.
    
* The critical-section problem: design a protocol that the processes can use to synchronize their activity so as to cooperatively share data.
    * Each process must request permission to enter its critical section. The section of code implementing this request is the **entry section**.
    * The critical section may be followed by an **exit section**.
    * The remaining code is the **remainder section**.

* A solution to the critical-section problem must satisfy the following three requirements:
    1. **Mutual exclusion**: no two processes should be executing in their critical sections at the same time.
    2. **Progress**: if no process is executing in its critical section and some processes wish to enter their critical section, then only those processes that are not executing in their remainder sections can participate in deciding which process will enter its CS next, and this selection can't be postponed indefinitely.
    3. **Bounded waiting**: there is a bound on the number of times that other processes are allowed to enter their critical sections after a process has made a request to enter its critical section and before that request is granted.
    
* two general approaches to handle critical sections in OSs:
    * preemptive kernels: allows a process to be preempted while it's running in kernel mode. need to ensure that shared kernel DS are free from race conditions. more responsive - less risk that a kernel-mode process will run for an arbitrarily long period. more suitable for real time programming sine it allows a real time process to preempt a process currently running in the kernel.
    * non-preemptive kernels: does not allow a process running in kernel mode to be preempted. this is free from race conditions - only one process is active in the kernel at a time.

## Peterson' solution
* software based solution:
    * no special support from the OS or specific h/w instructions to ensure Mutual exclusion.
    * no guarantee of working correctly on modern computer architectures because processors / compilers may reorder read / write operations that have no dependencies - for a multithreaded application with shared data, the reordering of instructions may render inconsistent / unexpected results.
* restricted to two processes P_i, P_j that alternate execution between their CS and remainder sections.
* both processes share:
    1. int turn: whose turn is it to enter its CS. if turn == i, P_i is allowed to execute its CS
    2. boolean flag\[2\] : flag\[i\] == true indicates that P_i is ready to enter its CS.

## H/W support for Synchronization

### memory barriers / memory fences:
* instructions that can force any changes in memory to be propagated to all other processors, thereby ensuring that memory modifications are visible to threads running on other processors.
* When a memory barrier instruction is performed, the system ensures that all loads and stores are completed before any subsequent load or store operations are performed.
* Therefore, even if instructions were reordered, the memory barrier ensures that the store operations are completed in memory and visible to other processors before future load or store operations are performed.

### H/W instructions
* Many modern computer systems provide special hardware instructions that allow us either to test and modify the content of a word or to swap the contents of two words atomically—that is, as one uninterruptible unit.
* if two test_and_set (or compare_and_swap) instructions are executed simultaneously on diff cores, then they will be executed sequentially in some arbitrary order. 
* We can use these special instructions to solve the critical-section problem in a relatively
simple manner:
    1. test_and_set(boolean *target): save the original value of target, set the target to true, return the original value.
        * while (test_and_set(&lock)); // wait until lock is false.
    2. compare_and_swap(int *value, int expected, int new_value) : save original value, set value to new_value if value == expected, return original value.
        * while ((&lock, 0, 1) != 0); // wait until the original lock was 0 and it was changed to 1 by current process i.e. acquire lock

### Atomic variables
* CAS not used directly to provide mutex. instead, CAS used as a basic building block for constructing other tools.
* atomic variable - one such tool
    * atomic operations on basic data types - integers, booleans
    * can be used to ensure mutex when there may be a data race on a single variable while it's being updated.
* Systems that support atomic variables:
    * provide special atomic data types
    * functions (implemented with CAS) for accessing and manipulating atomic variables are provided
* Atomic variables are commonly used in operating systems as well as concurrent applications, although their use is often limited to single updates of shared data such as counters and sequence generators.

* more robust, higher level tools that address race conditions in more generalized situations : mutex locks, semaphores, monitors

### Mutex Locks
* We use the mutex lock to protect critical sections and thus prevent race conditions.
* a process must acquire() the lock before entering a critical section, and it release()s the lock when it exits the critical section.
* A mutex lock has a boolean variable available whose value indicates if the lock is available or not.
    * If the lock is available, a call to acquire() succeeds, and the lock is then considered unavailable.
    * A process that attempts to acquire an unavailable lock is blocked until the lock is released.

* calls to acquire() and release() must be performed atomically. mutex locks can be implemented using the CAS operation.
* acquire() { while(!available); available = false; } OR acquire() { while !(&available, false, true); available = false; }
* release() { available = true; }
* spinlock : the process “spins” while waiting for the lock to become available.
* main disadvantage: busy waiting - While a process is in its critical section, any other process that tries to enter its critical section must loop continuously in the call to acquire(). Busy waiting also wastes CPU cycles that some other process might be able to use productively. we can avoid busy waiting by temporarily putting the waiting process to sleep and then awakening it once the lock
becomes available.
* Spinlocks advantage: no context switch is required when a process must wait on a lock, and a context switch may take considerable time.
* In certain circumstances on multicore systems, spinlocks are in fact the preferable choice for locking. If a lock is to be held for a short duration, one thread can “spin” on one processing core while another thread performs its critical section on another core. On modern multicore computing systems, spinlocks are widely used in many operating systems.

### Semaphores
* a more robust tool that can behave similarly to a mutex lock but can also provide more sophisticated ways for processes to synchronize their activities.
* A semaphore S is an integer variable that, apart from initialization, is accessed only through two standard atomic operations: wait() and signal(), i.e. when one process modifies the semaphore value, no other process can simultaneously modify that same semaphore value.
    * wait(S) {while (S <= 0); S--;}
    * signal(S) { S++; }
* types of semaphores:
    * counting semaphore: range over an unrestricted domain. used to control access to a given resource consisting of a finite number of instances. (initial value of S = # of resources).
    * binary semaphore: range = \[0,1\]. similar to mutex locks.
* example: two processes P1, P2. statement S2 of P2 must be executed after S1 of P1. let synch = 0.
    * P1: {S1; signal(synch);}
    * P2: {wait(synch); S2;}
* semaphore implementation:
    * there is busy waiting in wait()
    * another option
        * instead of busy waiting, the process can suspend itself and enter the waiting queue associated with the semaphore. The control is transferred to CPU scheduler, which selects another process to execute.
        * a suspended process waiting on a semaphore S should be restarted (wakeup()) when some other process executes a signal() operation. wakeup() changes the state from waiting state to ready state. Now it depends on CPU scheduler to schedule it.
        * a semaphore is a structure with the sem value and a list of processes waiting on that semaphore.
        * semaphore value may be negative. if it is, it's magnitude is the number of processes waiting on that semaphore.

        * wait(semaphore *S) {
        S->value--;
        if (S->value < 0) {add process to S->list; sleep();}}
        * signal(semaphore *S) {
        S->value++;
        if (S->value <= 0) {remove P from S->list; wakeup(P);}}
        * correct usage of semaphores does not depend on a particular queueing strategy for the semaphore lists.

### Monitors
* Although semaphores provide a convenient and effective mechanism for process synchronization, using them incorrectly can result in timing errors that are difficult to detect, since these errors happen only if particular execution sequences take place, and these sequences do not always occur.
* various types of errors can be generated easily when programmers use semaphores or mutex locks incorrectly to solve the critical-section problem. This situation may be caused by an honest programming error or an uncooperative programmer. eg:
    * signal(mutex); wait(mutex); - several processes may execute in CS
    * wait(mutex); wait(mutex); - process will permanently block on the second call to wait(), as the semaphore is unavailable.
    * process omits wait() or signal() - mut ex violated.
* One strategy for dealing with such errors is to incorporate simple synchronization tools as high-level language constructs.
* monitors: one fundamental high-level synchronization construct
    * ADT that includes a set of programmer defined operations that are provided with mut ex withing the monitor.
    * ensures that only one process at a time is active within the monitor. therefore, no need to code synchronization constraint explicitly.

### Liveness
* using synchronization tools may lead to indefinite waiting - a process attempting to enter its CS waits indefinitely.
* violates two requirements of a solution to CS problem: progress and bounded waiting
* **Liveness** : set of properties that a system must satisfy to ensure that processes make progress during their execution life cycle.
* A process waiting indefinitely is an example of a “liveness failure.”
* many different forms of liveness failure; however, all are generally characterized by poor performance and responsiveness.
* simple eg of a liveness failure : infinite loop.
* A busy wait loop presents the possibility of a liveness failure, especially if a process may loop an arbitrarily long period of time.
* Efforts at providing mutual exclusion using tools such as mutex locks and semaphores can often lead to such failures in concurrent programming.
* two situations that can lead to liveness failures:
    1. Deadlock
    2. Priority Inversion


* Deadlock:
    * The implementation of a semaphore with a waiting queue may result in a situation where two or more processes are waiting indefinitely for an event that can be caused only by one of the waiting processes. The event in question is the execution of a signal() operation. When such a state is reached, these processes are said to be deadlocked.
    * a set of processes is in a deadlocked state when every process in the set is waiting for an event that can be caused only by another process in the set. The “events” with which we are mainly concerned here are the acquisition and release of resources such as mutex locks and semaphores.


* Priority Inversion:
    * when a process with lower priority affects how long a higher priority process must wait.
    * avoided by priority-inheritance protocol: all processes that are accessing resources needed by a higher-priority process inherit the higher priority until they are finished with the resources in question.
    * When they are finished, their priorities revert to their original values.































