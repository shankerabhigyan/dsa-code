#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

ListNode* detectCycle(ListNode* A){
    if(A->next==nullptr) return nullptr;

    ListNode* temp = A;
    unordered_map<ListNode*,bool> visited;
    while(temp!=nullptr){
        if(visited[temp]){
            return temp;
        }
        else{
            visited[temp] = true;
            temp = temp->next;
        }
    }
    return nullptr;
}