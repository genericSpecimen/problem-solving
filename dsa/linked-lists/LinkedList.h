struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct LinkedList {
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    int size = 0;
    
    bool isEmpty() {
        return (size == 0);
    }
    
    void push_back(int x) {
        if (isEmpty()) {
            head = new ListNode(x);
            tail = head;
        } else {
            tail->next = new ListNode(x);
            tail = tail->next;
        }
        size++;
    }
    
    void print_list(ListNode *curr) {
        while (curr != nullptr) {
            std::cout << curr->val << " -> ";
            curr = curr->next;
        }
        
        std::cout << "null\n";
    }
};
