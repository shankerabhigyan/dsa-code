#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(NULL){}
    Node(int x): val(x), next(NULL){}
    Node(int x, Node* next): val(x), next(next){}
};

Node* removeNthFromEnd(Node* head, int n){
    Node* dummy = new Node(0, head);
    Node* slow = dummy;
    Node* fast = dummy;
    for(int i = 0; i < n; i++){
        fast = fast->next;
    }
    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}