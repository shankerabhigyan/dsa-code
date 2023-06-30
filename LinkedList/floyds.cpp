// Floyd's cycle detection algorithm
// https://leetcode.com/problems/linked-list-cycle/description/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr){}
    Node(int x): val(x), next(nullptr){}
    Node(int x, Node* ptr): val(x), next(ptr){}
};

Node* Floyds(Node* &head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return slow;
        }
    }
    return NULL;
}   

Node* getStartNode(Node* head){
    Node* intersection = Floyds(head);
    if (head == NULL || head->next == NULL || intersection == NULL){
        return NULL;
    }
    
    Node* slow = head;
    Node* fast = intersection;
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next
    }
    return slow;    
}

void removeLoop(Node* start){
    Node* node = start;
    while(node->next != node){
        node = node->next;
    }
    node->next = NULL;
    return;
}