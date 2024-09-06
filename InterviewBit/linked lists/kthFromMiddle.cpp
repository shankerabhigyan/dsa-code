#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

int kthFromMiddle(ListNode* A, int B){
    bool alt = true;
    ListNode* middle = A;
    ListNode* temp = A;
    ListNode* prev = nullptr;
    while(temp->next!=nullptr){
        if(alt){
            temp=temp->next;
            ListNode* temp2 = prev;
            prev = middle;
            middle = middle->next;
            prev->next = temp2;
            alt = !alt;
        }
        else{
            temp = temp->next;
            alt=!alt;
        }
    }
    middle->next = prev;
    ListNode* revhead = middle;
    while(B>0){
        if(revhead==nullptr) return -1;
        revhead = revhead->next;
        B--;
    }
    if(revhead==nullptr) return -1;
    return revhead->val;
}
