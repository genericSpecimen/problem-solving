# Database
* tradtional DB applns: most info stored/processed is either textual or numeric
* Big data / NoSQL systems (Not only SQL)
    * store and manage non-tradtional data such as posts, tweets, images, video clips.
    * fast search and retrieval, reliable storage of such data. 
    * do not require meta-data. data is stored as self-descibing data that includes data item names and data values together in one structure.
    * depending on appln requirements, some data may be stored using SQL systems, other data would be stored using NoSQL.

* data : known facts that can be recorded, and have implicit meaning - names, numbers, addresses
* database : collection of related data with an implicit meaning. DB has following implicit properties:
    * some source from which data is derived
    * some degree of interaction with events in the real world
    * intended users / applications
* DB can be maintained manually / through computers
* DBMS: computerized system that enables users to create and maintain a DB. It facilitates:
    * defining - specify data types, structures, constraints of data to be stored. DB defintion is stored by DBMS in the form of database catalog / dictionary called meta-data.
    * constructing - storing the data on some storage medium controlled by the DBMS
    * manipulating - querying, updating, generating reports
    * sharing databases among various users and applications
    * Protecting the DB - against h/w or s/w malfunction (crashes), security protection against unauthorized users / malicious access
    * Maintain the DB system by allowing the system to evolve as requirements change over time.
* Appln pgms access the DB by sending queries / requests to the DBMS.
* Database system : DB + DBMS software

## DB approach vs Traditional File processing approach
### FP approach
* write customized pgms to access data stored in files
* each user defines and implements the files needed for a specific s/w appln as part of pgming the appln.
* different users (of diff applns) interested in the same data must maintain separate files and pgms to manipulate these files because each requires some data not available from other user's files.
* redundancy in defining and storing data, wastes storage space, requires redundant efforts to maintain common up to date data.
    * duplication of effort - need to perform a single logical update multiple times: once for each file in which the data is stored.
    * wasted storage space, a big problem in large DBs
    * files that represent the same data may become inconsistent - eg. updates applied to one file but not to the others, or if applied to all files, updates applied independently by user groups may not be consistent. eg. diff DOB entered by diff groups.
* constrained to work with only one specific DB, whose structure (data definition) is declared in the appln pgms.
* any change to a structure of a file may require changing all programs that access that file

### DB approach
* single repo maintains data which is defined once and accessed by various users repeatedly through queries, transactions, and appln pgms
* self-describing nature of a DB system - DB + complete definition / description of the DB structure and constraints (meta-data) - stored in DBMS catalog.
    * general purpose DBMS software must work with any number of DB applns (uni DB, bank DB, etc).
    * therefore, it refers to DBMS catalog to know the structure of the files in a specific DB.
    * As a result, DBMS S/W can access diverese DBs by extracting the DB definitions from the DBMS catalog and using these defintions
* data abstraction
    * DBMS provides a conceptual representation of data that doesn't include many details - how data is stored, how operations are implemented.
        * pgm-data independence - changes to structure of a file do not require changing DBMS access pgms in most cases. Structure of data files stored in DBMS catalog is separate from the access pgms
        * pgm-operation independence - In OO and Object-relational DBs, user appln pgms can operate on data by invoking custom operations (functions) through their names and args (well-defined interface), regardless of how the operations are implemented
    * Data Model: type of data abstraction used to provide conceptual representation.
        * Uses logical concepts, such as objects, their properties, and their interrelationships - easier for most users to understand than computer storage concepts
        * hides storage and implementation details that aren't of interest to most DB users.
    * DB users and appln pgms refer to the conceptual representation of the files, and the DBMS extracts the details of file storage from the catalog when these are needed by the DBMS file access modules.
* support of multiple views of the data
    * DB has many types of users, each may require a diff view of the DB
    * view : virtual data derived from the DB files but not explicitly stored.
* multiuser / multi-applns DBMS
    * sharing of data among multiple users at the same time
    * multiuser transaction processing
    * DBMS must include concurrency control s/w to ensure that several users trying to update the same data do so in a controlled manner and the result of the updates is correct.
    * ensure concurrent transactions operate correctly and efficiently.

#### Adv of using DBMS approach
* Controlling redundancy: view of different user groups are integrated during DB design.
    * **Data Normalization**: Ideally, we should have a DB design that stores each logical data item (name, dob) in only one place in the DB. This ensures consistency and saves storage space.
    * Denormalization: In practice, it's sometimes necessary to use controlled redundancy to improve the perf of queries since we don't have to search multiple files to collect the data. DBMS should have the capability to control this redundancy in order to prohibit inconsistentencies among files by specifying checks during DB design and enforced by DBMS whenever files are updated

* Availability of up to date info - a DBMS makes the DB available to all users. One user's update is immediately visible to all other users. This is essential for many transaction processing applns, such as reservation systems, banking DBs, and is made possible by the concurrency control and recovery subsystems of a DBMS.
    
* Restricting unauthorized access - diff user groups given login ids / passwords to gain diff levels of access to the DB. DBMS provides a security and authorization subsystem which the DBA uses to create accounts and to specify account restrictions. Then, DBMS should enforce these restrictions automatically.

* Providing persistent storage for pgm objects - OO DB systems.
    * persistent: survives the termination of pgm execution and can later be retrived by another pgm.
    * must convert structs / classes with complex structures into a format suitable for file storage.
    * DBMS automatically performs these conversions 
    * eg. a complex object in C++ can be stored permanently in an OO DBMS. Such an obj is persistent.
    * OO DB systems typically offer data structure compatibility with one ir more OO pgmming langs.

* Providing storage structures and search techniques for efficient query processing:
    * DB typically stored on disk, disk search is needed for the desired records. DBMS provides specialized data structures and search techniques.
    * Indexes: Auxiliary files called indexes are used to speed up disk search. Indexes are based on tree data structures or hash data structures suitably modified for disk search.
        * Which indexes to create and maintain - part of physical DB design and tuning - done by DBA staff.
    * disk-to-mem Buffering / Caching : this DBMS module maintains parts of the DB in main memory buffers. Crucial to DBMS perf.
    * query processing and optimization: chooses an efficient query execution plan for each query based on the existing storage structures.
* Providing backup and recovery from h/w, s/w failures. e.g. need backup to recover from a disk failure, rollback unfinished transaction in case of pgm crash.

* Providing multiple UIs - diff types of users, varying levels of technical knowledge
* Representing complex relationships among data
* Enforcing integrity constraints - DBMS must be capable to define and enforce these constraints. DB designers identify integrity constraints during DB design. They are derived from the meaning / semantics of the data. Eg:
    * Data type for each data item
    * Referential integrity: a record in a file must be related to records in other files.
    * Key / Uniqueness constraint: no two records with the same value in this column.
* Permitting inferencing and actions using rules and triggers.
    * Deductive DB systems provide capabilities for defining deduction rules for inferencing new information from the stored DB facts.
    * In today's relational DB systems, we can associate **triggers** with tables.
        * trigger - form of a rule activated by updates to the table, which may result in additional operations to some other tables , and so on.
        * stored procedure - more involved procedures to enforce rules - they become part of the DB definition.
    
* transaction
    * executing program / process that includes one or more DB accesses, such as reading / updating of DB records.
    * supposed to execute a logically correct DB access if executed in its entirety without interference from other transactions
    * DBMS must enforce several transaction properties (ACID):
        * Atomicity: either all or none of the DB operations in a transaction are executed.
        * Consistency
        * Isolation: each transaction appears to execute in isolation from other transactions, even though hundreds of transactions may be executing concurrently
        * 
        
## Actors on the scene
People whose jobs involve the day to day use of a large DB

* DB administrators: administering resources : DB and DBMS - authorizing access, coordinating and monitoring its use, acquiring hw and sw resources as needed. accountable for security breaches, poor system response time
* DB Designers: identify the data to be stored in the DB and choose the appropriate structures to represent and store this data. They interact with each potential group of users and develop views of the DB that meet the data and processing requirements of these groups.
* End users: require access to the DB for querying, updating, generating reports.
* System analysts, appln pgmmers (SDE) should be familiar with the full range of capabilities provided by the DBMS to accomplish their tasks (develop specifications for standard canned transactions and implement these as pgms)


## Workers behind the scene
People who work to maintain the DB system environment; not actively interested in the DB contents

* DBMS system designers and implementers. DBMS is a very complex s/w system with many modules for:
    * DBMS catalog
    * query lang processing
    * interface processing
    * accessing / buffering data
    * controlling concurrency
    * handling data recovery / security
* Tool developers - design optional packages for DB design, perf monitoring, gui, prototyping, simulation, test data generation, etc.
* operators and maintenance (sysadmin) personnel: responsible for actual running and maintenance of the h/w and s/w env for the DB system.

## When not to use a DBMS
DBMS S/W overhead:

* high initial investment in h/w, s/w, training
* providing security, concurrency control, recovery, integrity functions
* large s/w size

Better to develop customized DB applns if:

* simple, well defined DB applns not expected to change at all
* stringent, real time requirements for appln pgms that may not be met due to DBMS overhead.
* embedded systems with limited storage, where a general purpose DBMS would not fit.
* multiple-user access to data not required.

