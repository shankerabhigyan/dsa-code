SinglyLinkedListNode* removeNodes(SinglyLinkedListNode* listHead, int x) {
    // Handle empty list case
    if (listHead == nullptr) {
        return nullptr;
    }
    
    // If head node(s) need to be removed
    while (listHead != nullptr && listHead->data > x) {
        SinglyLinkedListNode* temp = listHead;
        listHead = listHead->next;
        delete temp;
    }
    
    // If list becomes empty after removing head nodes
    if (listHead == nullptr) {
        return nullptr;
    }
    
    // Remove nodes greater than x from the rest of the list
    SinglyLinkedListNode* current = listHead;
    while (current->next != nullptr) {
        if (current->next->data > x) {
            // Store node to be deleted
            SinglyLinkedListNode* temp = current->next;
            // Update the link
            current->next = current->next->next;
            // Delete the node
            delete temp;
        } else {
            current = current->next;
        }
    }
    
    return listHead;
}



