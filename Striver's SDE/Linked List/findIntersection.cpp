// https://leetcode.com/problems/intersection-of-two-linked-lists/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(NULL){}
    Node(int x): val(x), next(NULL){}
    Node(int x, Node* next): val(x), next(next){}
};

Node* getIntersectionNode(Node* headA, Node* headB){
    Node* temp1 = headA;
    Node* temp2 = headB;
    unordered_map<Node*,bool> m;
    while(temp1!=NULL || temp2!=NULL){
        if(m[temp1] || m[temp2] ||temp1==temp2){
            if(temp1==temp2){
                return temp1;
            }
            if(m[temp1]){
                return temp1;
            }
            else{
                return temp2;
            }
        }
        if(temp1!=NULL){
            m[temp1] = true;
            temp1 = temp1->next;
        }
        if(temp2!=NULL){
            m[temp2] = true;
            temp2 = temp2->next;
        }
    }
    return NULL;
}

Node* getIntersectionNode2(Node* headA, Node* headB){
    Node* temp1 = headA;
    Node* temp2 = headB;
    while(temp1!=temp2){
        if(temp1==NULL){
            temp1 = headB;
        }
        else{
            temp1 = temp1->next;
        }
        if(temp2==NULL){
            temp2 = headA;
        }
        else{
            temp2 = temp2->next;
        }
    }
    return temp1;
}