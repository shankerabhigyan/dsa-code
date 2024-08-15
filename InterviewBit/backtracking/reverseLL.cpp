#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* backtrack(ListNode* node, ListNode** head){
    if(node->next==NULL){
        *head = node;
        return node;
    }
    else{
        ListNode* p = backtrack(node->next, head);
        p->next = node;
        return node;
    }
}

ListNode* reverseList(ListNode* A){
    if(A==NULL) return NULL;
    if(A->next==NULL) return A;
    ListNode* head = nullptr;
    ListNode* tail = backtrack(A,&head);
    tail->next = NULL;
    return head;
}

int main(){

    return 0;
}