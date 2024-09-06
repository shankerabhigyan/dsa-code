#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

ListNode* partition(ListNode* A, int B){
    ListNode* smaller=nullptr;
    ListNode* smallerhead = nullptr;
    ListNode* bigger = nullptr;
    ListNode* biggerhead=nullptr;
    while(A!=nullptr){
        if(A->val<B){
            if(smallerhead==nullptr){
                smaller = A;
                smallerhead = A;
            }
            else{
                smaller->next = A;
                smaller = smaller->next;
            }
        }
        else{
            if(biggerhead==nullptr){
                bigger = A;
                biggerhead = A;
            }
            else{
                bigger->next = A;
                bigger = bigger->next;
            }
        }
        A = A->next;
    }
    if(smallerhead==nullptr){
        return biggerhead;
    }
    else{
        smaller->next = biggerhead;
        if(bigger!=nullptr){
            bigger->next = nullptr;
        }
        return smallerhead;
    }
}