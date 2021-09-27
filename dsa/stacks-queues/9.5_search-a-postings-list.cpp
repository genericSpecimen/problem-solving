void setJumpOrderHelper(ListNode *head, int &order) {
    if (head != nullptr && head->order == -1) {
        head->order = order++;
        setJumpOrderHelper(head->jump, order);
        setJumpOrderHelper(head->next, order);
    }
}

void setJumpOrder(ListNode *head) {
    if (head == nullptr) return;
    
    int order = 0;
    
    // recursive
    // setJumpOrderHelper(head, order);
    
    // iterative
    stack<ListNode*> st;
    st.push(head);
    
    while (!st.empty()) {
        ListNode *curr = st.top(); st.pop();
        
        if (curr->order != -1) continue; // already visited
        
        // if not already visited, then mark order
        curr->order = order++;
        
        // then visit jump and next nodes
        // (note the flipped order of pushing to process jump before next)
        if (curr->next != nullptr) st.push(curr->next);
        if (curr->jump != nullptr) st.push(curr->jump);
    }
}

