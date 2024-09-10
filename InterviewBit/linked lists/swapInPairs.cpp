#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

ListNode* swapInPairs(ListNode* A){
    if(A->next==nullptr) return A;
    ListNode* curr = A;
    ListNode* head = nullptr;
    ListNode* temp = nullptr;
    while(curr!= nullptr && curr->next!=nullptr){
        ListNode* next = curr->next;
        curr->next = next->next;
        next->next = curr;
        if(head==nullptr){
            head = next;
            temp = curr;
            curr = curr->next;
        }
        else{
            temp->next = next;
            temp = curr;
            curr = curr->next;
        }
    }
    return head;
}

int main(){
    ListNode* A = new ListNode(1);
    A->next = new ListNode(2);
    A->next->next = new ListNode(3);
    A->next->next->next = new ListNode(4);
    A->next->next->next->next = new ListNode(5);
    A->next->next->next->next->next = new ListNode(6);
    A->next->next->next->next->next->next = new ListNode(7);
    A->next->next->next->next->next->next->next = new ListNode(8);

    ListNode* head = swapInPairs(A);
    while(head!=nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;

    return 0;
}