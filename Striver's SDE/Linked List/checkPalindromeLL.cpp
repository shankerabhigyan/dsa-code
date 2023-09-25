#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(NULL){}
    Node(int x): val(x), next(NULL){}
    Node(int x, Node* next): val(x), next(next){}
};

bool isPalindrome(Node* head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* mid = slow;
    Node* prev = NULL;
    Node* curr = mid->next;
    Node* next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    mid->next = prev;
    Node* temp = head;
    while(mid->next!=NULL){
        if(temp->val!=mid->next->val){
            return false;
        }
        temp = temp->next;
        mid = mid->next;
    }
    return true;
}

bool isPalindrome2(Node* head){
    vector<int> v;
    Node* temp = head;
    while(temp!=NULL){
        v.push_back(temp->val);
        temp = temp->next;
    }
    int i=0, j=v.size()-1;
    while(i<j){
        if(v[i]!=v[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}