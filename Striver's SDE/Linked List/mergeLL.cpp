#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(NULL){}
    Node(int x): val(x), next(NULL){}
    Node(int x, Node* next): val(x), next(next){}
};

Node* Merge(Node* list1, Node* list2){
    if(!list1) return list2;
    if(!list2) return list1;
    if(list1->val < list2->val){
        list1->next = Merge(list1->next, list2);
        return list1;
    }
    else{
        list2->next = Merge(list1, list2->next);
        return list2;
    }
}