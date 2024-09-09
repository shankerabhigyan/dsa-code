#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

int isPalindromeLL(ListNode* A){
    if(A==nullptr) return 0;
    if(A->next == nullptr) return 1;
    ListNode* slow = A;
    ListNode* fast = A;
    vector<int> v;
    while(fast->next!=nullptr && fast->next->next!=nullptr){
        v.push_back(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }
    v.push_back(slow->val);
    slow = fast->next==nullptr?slow:slow->next;
    int i=v.size()-1;
    while(slow!=nullptr){
        if(v[i]!=slow->val) return 0;
        i--;
        slow = slow->next;
    }
    return 1;
}

int main(){
    return 0;
}