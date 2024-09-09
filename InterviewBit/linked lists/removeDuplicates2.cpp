#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* A){
    if(A->next == nullptr) return A;
    ListNode* head = nullptr;
    ListNode* temp = nullptr;
    ListNode* t = A;
    unordered_map<int,bool>visited;
    while(t->next!=nullptr){
        if(t->val != t->next->val && !visited[t->val]){
            if(head==nullptr){
                head = t;
                temp = t;
                t = t->next;
            }
            else{
                temp->next = t;
                temp = temp->next;
                t = t->next;
            }
            visited[temp->val] = true;
        }
        else{
            t = t->next;
        }
    }
    if(head==nullptr) return head;
    else{
        temp->next = nullptr;
    }
}

int main(){
    return 0;
}