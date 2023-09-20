// https://leetcode.com/problems/reverse-linked-list/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(NULL){}
    Node(int x): val(x), next(NULL){}
    Node(int x, Node* next): val(x), next(next){}
};

Node* reverseLL(Node* head){ // 7ms leetcode
    if(head==NULL || head->next==NULL){
        return head;
    }
    stack<Node*> st;
    Node* temp = head;
    while(temp->next!=NULL){
        st.push(temp);
        temp = temp->next;
    }
    Node* newhead = temp;
    while(!st.empty()){
        temp->next = st.top();
        temp = st.top();
        st.pop();
    }
    temp->next = NULL;
    return newhead;
}

Node* reverseLL2(Node* head){ // 3ms leetcode
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* n1 = head;
    Node* n2 = head->next;
    n1->next = NULL;
    while(n2!=NULL){
        Node* temp = n2->next;
        n2->next = n1;
        n1 = n2;
        n2 = temp;
    }
    return n1;
}

int main(){

    return 0;
}