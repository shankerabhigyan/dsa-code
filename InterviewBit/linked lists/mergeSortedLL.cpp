#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* A, ListNode* B){
    if(A==nullptr || B==nullptr){
        return A==nullptr?A:B;
    }
    ListNode* h1 = A;
    ListNode* h2 = B;
    ListNode* head = nullptr;
    ListNode* temp = nullptr;
    if(h1->val < h2->val){
        head = h1;
        temp = h1;
        h1 = h1->next;
    }
    else{
        head = h2;
        temp = h2;
        h2 = h2->next;
    }
    while(h1!=nullptr && h2!=nullptr){
        if(h1->val < h2->val){
            temp->next = h1;
            temp = temp->next;
            h1 = h1->next;
        }
        else{
            temp->next = h2;
            temp = temp->next;
            h2 = h2->next;
        }
    }
    if(h1==nullptr && h2!=nullptr){
        while(h2!=nullptr){
            temp->next = h2;
            temp = temp->next;
            h2 = h2->next;
        }
    }
    if(h2==nullptr && h1!=nullptr){
        while(h1!=nullptr){
            temp->next = h1;
            temp=temp->next;
            h1 = h1->next;
        }
    }
    return head;
}

int main(){
    return 0;
}