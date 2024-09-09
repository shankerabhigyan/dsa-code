#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

ListNode* Solution::removeNthFromEnd(ListNode* A, int B){
    if(A->next==nullptr) return B==1?nullptr:A;
    ListNode* slow = A;
    ListNode* fast = A;
    int count = 1;
    while(fast->next!=nullptr && fast->next->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        count++;
    }
    int length = fast->next==nullptr?count*2-1:count*2; // odd length:even length
    ListNode* temp = A;
    int rem = length - B;
    if(rem<=0){
        ListNode* head = A->next;
        return head;
    }
    while(rem>1){
        temp = temp->next;
        rem--;
    }
    temp->next = temp->next->next;
    return A;
}

int main(){
    return 0;
}