// https://www.codingninjas.com/studio/problems/circularly-linked_1070232?source=youtube&campaign=Lovebabbar_codestudio_26thjan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar_codestudio_26thjan
// Find if the given Linked List is circular or not.
// use slow and fast pointers

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr){}
    Node(int x): val(x), next(nullptr){}
    Node(int x, Node* ptr): val(x), next(ptr){}
};

bool isCircular(Node* &head){
    if(head == NULL || head->next == NULL){
        return false;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}

