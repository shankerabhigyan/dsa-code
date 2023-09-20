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
    if(list1==NULL){
        return list2;
    }
    if(list2==NULL){
        return list1;
    }
    Node* n1 = list1;
    Node* n2 = list2;
    Node* curr = n1;
    while(n1!=NULL && n2!=NULL){
        
    }

}