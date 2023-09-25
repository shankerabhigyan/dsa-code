#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/linked-list-cycle-ii/

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(NULL){}
    Node(int x): val(x), next(NULL){}
    Node(int x, Node* next): val(x), next(next){}
};

Node* detectCycle(Node* head){
    
}