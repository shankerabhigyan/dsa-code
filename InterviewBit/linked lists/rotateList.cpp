#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

ListNode* rotateRight(ListNode* A, int B){
    int length = 1;
    ListNode* temp = A;
    while(temp->next!=nullptr){
        length++;
        temp = temp->next;
    }
    temp->next = A;
    B = B%length;
    int idx = length-B;
    temp = A;
    while(idx>1){
        temp = temp->next;
        idx--;
    }
    ListNode* newHead = temp->next;
    temp->next = nullptr;
    return newHead;
}

int main(){
    ListNode* A = new ListNode(1);
    A->next = new ListNode(2);
    A->next->next = new ListNode(3);
    A->next->next->next = new ListNode(4);
    A->next->next->next->next = new ListNode(5);

    ListNode* head = rotateRight(A, 6);
    while(head!=nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
    return 0;
}