#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

ListNode* reversedList(ListNode* A){
    ListNode* temp=A;
    ListNode* prev=nullptr;
    while(temp!=nullptr){
        ListNode* temp2 = temp->next;
        temp->next = prev;
        prev = temp;
        temp = temp2;
    }
    return prev;
}