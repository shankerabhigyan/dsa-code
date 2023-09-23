// https://leetcode.com/problems/reverse-nodes-in-k-group/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(NULL){}
    Node(int x): val(x), next(NULL){}
    Node(int x, Node* next): val(x), next(next){}
};

Node* reverseK(Node* head, int k){
    if(k==1){
        return head;
    }
    Node* temp = head;
    stack<Node*> st;
    Node* nhead = new Node(0);
    Node* t = nhead;
    while(temp!=NULL){
        st.push(temp);
        temp = temp->next;
        if(st.size()==k){
            while(!st.empty()){
                t->next = st.top();
                st.pop();
                t = t->next;
            }
            t->next=NULL;
        }
    }
    while(!st.empty()){
        t->next = st.top();
        st.pop();
    }
    return nhead->next;
}