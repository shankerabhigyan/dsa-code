#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

ListNode* reverse(ListNode* node) {
    if(node->next==nullptr) return node;
    ListNode* prev = nullptr;
    ListNode* curr = node;
    ListNode* next = nullptr;

    while (curr != nullptr) {
        next = curr->next; 
        curr->next = prev;  
        prev = curr; 
        curr = next;
    }
    return prev;
}

ListNode* reorderList(ListNode* A){
    if(A->next==nullptr || A->next->next==nullptr) return A;
    ListNode* slow = A;
    ListNode* fast = A;
    ListNode* prev = nullptr;
    while(fast->next!=nullptr && fast->next->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* cc = slow->next;
    slow->next = nullptr;
    ListNode* head2 = reverse(cc);
    
    // **********
    ListNode* n1 = A;
    ListNode* n2 = head2;
    ListNode* n3 = nullptr;
    while(n2!=nullptr){
        n3 = n1->next;
        n1->next = n2;
        n1 = n2;
        n2 = n3;
    }
    return A;
}

int main(){
    ListNode* A = new ListNode(1);
    A->next = new ListNode(2);
    A->next->next = new ListNode(3);
    A->next->next->next = new ListNode(4);
    A->next->next->next->next = new ListNode(5);
    //A->next->next->next->next->next = new ListNode(6);

    ListNode* head = reorderList(A);
    while(head!=nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout << endl;
    return  0;
}