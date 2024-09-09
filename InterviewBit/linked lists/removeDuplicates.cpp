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
    head = t;
    temp = t;
    t = t->next;
    temp->next = nullptr;
    visited[head->val] = true;
    while(t!=nullptr){
        if(!visited[t->val]){
            // unrepeated element
            temp->next = t;
            temp = temp->next;
            t = t->next;
            temp->next = nullptr;
            visited[temp->val] = true;
        }
        else{
            // repeated element
            t = t->next;
        }
    }
    return head;
}

int main(){
    ListNode* A = new ListNode(1);
    A->next = new ListNode(1);
    A->next->next = new ListNode(2);
    A->next->next->next = new ListNode(3);
    A->next->next->next->next = new ListNode(3);
    A->next->next->next->next->next = new ListNode(4);
    A->next->next->next->next->next->next = new ListNode(5);
    A->next->next->next->next->next->next->next = new ListNode(5);
    A->next->next->next->next->next->next->next->next = new ListNode(6);

    ListNode* head = deleteDuplicates(A);
    while(head!=nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
    return 0;
}