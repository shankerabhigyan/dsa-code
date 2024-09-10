#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

ListNode* solve(ListNode* A, int B){
    if(A->next==nullptr) return A;
    int length = 1;
    ListNode* temp = A;
    while(temp->next!=nullptr){
        length++;
        temp = temp->next;
    }
    int i=0;
   
}

int main(){
    ListNode* A = new ListNode(1);
    A->next = new ListNode(2);
    A->next->next = new ListNode(3);
    A->next->next->next = new ListNode(4);
    // A->next->next->next->next = new ListNode(5);
    // A->next->next->next->next->next = new ListNode(6);
    // A->next->next->next->next->next->next = new ListNode(7);
    // A->next->next->next->next->next->next->next = new ListNode(8);
    // A->next->next->next->next->next->next->next->next = new ListNode(9);

    ListNode* head = solve(A, 2);
    while(head!=nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
    return 0;
}