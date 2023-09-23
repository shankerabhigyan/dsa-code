// https://leetcode.com/problems/add-two-numbers/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(NULL){}
    Node(int x): val(x), next(NULL){}
    Node(int x, Node* next): val(x), next(next){}
};

Node* addTwoNumbers(Node* l1, Node* l2){
    Node* ans = new Node();
    Node* temp = ans;
    Node* t1 = l1;
    Node* t2 = l2;
    int carry = 0;
    while(t1!=NULL && t2!=NULL){
        temp->next = new Node();
        temp = temp->next;
        int x = t1->val + t2->val + carry;
        carry = 0;
        if(x>=10){
            temp->val = x-10;
            carry = 1;
        }
        else{
            temp->val = x;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    while(t1!=NULL){
        temp->next = new Node();
        temp = temp->next;
        int x = t1->val + carry;
        carry = 0;
        if(x>=10){
            temp->val = x-10;
            carry = 1;
        }
        else{
            temp->val = x;
        }
        t1 = t1->next;
    }
    while(t2!=NULL){
        temp->next = new Node();
        temp = temp->next;
        int x = t1->val + carry;
        carry = 0;
        if(x>=10){
            temp->val = x-10;
            carry = 1;
        }
        else{
            temp->val = x;
        }
        t2 = t2->next;
    }
    if(carry!=0){
        temp->next = new Node();
        temp = temp->next;
        temp->val = carry;
    }
    return ans->next;
}

Node* addTwoNumbers2(Node* l1, Node* l2){
    Node* ans = new Node();
    Node* temp = ans;
    Node* t1 = l1;
    Node* t2 = l2;
    int carry = 0;
    while(t1!=NULL || t2!=NULL){
        temp->next = new Node();
        temp = temp->next;
        int x = 0;
        if(t1!=NULL){
            x += t1->val;
            t1 = t1->next;
        }
        if(t2!=NULL){
            x += t2->val;
            t2 = t2->next;
        }
        x += carry;
        carry = 0;
        if(x>=10){
            temp->val = x-10;
            carry = 1;
        }
        else{
            temp->val = x;
        }
    }
    if(carry!=0){
        temp->next = new Node();
        temp = temp->next;
        temp->val = carry;
    }
    return ans->next;
}