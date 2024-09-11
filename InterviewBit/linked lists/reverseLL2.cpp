#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

void reverse(ListNode* head, ListNode* tail){
    if(head==tail) return;
    ListNode* curr = head->next;
    ListNode* prev = head;
    prev->next = nullptr;
    while(curr!=nullptr){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return;
}

ListNode* reverseBetween(ListNode* A, int B, int C){
    if(A->next==nullptr) return A;

    ListNode* curr = A;
    ListNode* start = curr;
    ListNode* before = nullptr;
    while(B>1){
        before = start;
        start=start->next;
        B--;
        C--;
    }

    ListNode* end = start;
    while(C>1){
        end = end->next;
        C--;
    }
    ListNode* after = end->next;
    end->next = nullptr;
    reverse(start,end);
    ListNode* head = A;
    if(before==nullptr){
        head = end;
        start->next = after;
    }
    else{
        before->next = end;
        start->next = after;
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

    ListNode* head = reverseBetween(A,1,4);
    while(head!=nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
    return 0;
}