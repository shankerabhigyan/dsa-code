#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

ListNode* insertionSortList(ListNode* A){
    if(A==nullptr) return nullptr;
    if(A->next == nullptr) return A;

    ListNode* t = A->next;
    ListNode* t2 = t->next;
    ListNode* newhead = A;
    newhead->next = nullptr;
    while(t!=nullptr){
        t->next = newhead;
        ListNode* temp = newhead;
        ListNode* prev = t;
        bool insert = false;
        while(temp!=nullptr){
            if(t->val<=temp->val && t->val>=prev->val){
                if(prev!=t){
                    prev->next = t;
                    t->next = temp;
                    insert = true;
                    break;
                }
                else{
                    newhead = t;
                    insert = true;
                    break;
                }
                
            }
            temp = temp->next;
            prev = prev->next;
        }
        if(!insert){
            prev->next = t;
            t->next = temp;
        }
        t = t2;
        t2 = t2==nullptr?t2:t2->next;
    }
    return newhead;
}