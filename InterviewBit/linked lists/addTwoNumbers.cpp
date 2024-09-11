#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* A, ListNode* B){
    if(A==nullptr || B==nullptr) return A==nullptr?A:B;
    
    ListNode* p1 = A;
    ListNode* p2 = B;
    ListNode* sumhead = nullptr;
    ListNode* psum = nullptr;
    int carry = 0;
    while(p1!=nullptr && p2!=nullptr){
        int x = p1->val + p2->val + carry;
        carry = x/10;
        x = x%10;
        if(sumhead==nullptr){
            sumhead = new ListNode(x);
            psum = sumhead;
        }
        else{
            psum->next = new ListNode(x);
            psum = psum->next;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    if(p1!=nullptr){
        while(p1!=nullptr){
            int x = p1->val + carry;
            carry = x/10;
            x = x%10;
            psum->next = new ListNode(x);
            psum = psum->next;
            p1=p1->next;
        }
    }
    if(p2!=nullptr){
        while(p2!=nullptr){
            int x = p2->val + carry;
            carry = x/10;
            x = x%10;
            psum->next = new ListNode(x);
            psum = psum->next;
            p2=p2->next;
        }
    }
    if(carry!=0){
        psum->next = new ListNode(carry);
        psum = psum->next;
    }
    return sumhead;
}

int main(){
    ListNode* A = new ListNode(3);
    A->next = new ListNode(4);
    A->next->next = new ListNode(2);

    ListNode* B = new ListNode(4);
    B->next = new ListNode(6);
    B->next->next = new ListNode(5);

    ListNode* head = addTwoNumbers(A,B);
    while(head!=nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
    return 0;
}