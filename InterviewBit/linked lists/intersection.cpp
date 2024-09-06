#include<bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/intersection-of-linked-lists/

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

ListNode* getIntersection(ListNode* A, ListNode* B){
    if(A==nullptr || B==nullptr) return nullptr;
    ListNode* ptra = A;
    ListNode* ptrb = B;
    unordered_map<ListNode*,bool> map;
    while(ptra!=nullptr || ptrb!=nullptr){
        if(map[ptra]){
            return ptra;
        }
        if(ptra!=nullptr) map[ptra]=true;
        if(map[ptrb]){
            return ptrb;
        }
        if(ptrb!=nullptr) map[ptrb]=true;
        ptra = ptra==nullptr?ptra:ptra->next;
        ptrb = ptrb==nullptr?ptrb:ptrb->next;
    }
    return nullptr;
}
