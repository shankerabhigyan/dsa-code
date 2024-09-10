#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

ListNode* evenReverse(ListNode* A){
    if(A->next==nullptr) return A;
    stack<ListNode*> st;
    int i=1;
    ListNode* temp = A;
    while(temp!=nullptr && temp->next!=nullptr){
        st.push(temp->next);
        ListNode* t = temp->next->next;
        temp->next->next = nullptr;
        temp->next = t;
        temp = temp->next;
    }
    temp = A;
    while(!st.empty()){
        ListNode* top = st.top();
        st.pop();
        ListNode* t = temp->next;
        temp->next = top;
        temp = temp->next;
        temp->next = t;
        temp = temp->next;
    }
    return A;
}

int main(){
    return 0;
}