#include<bit/stdc++.h>
using namespace std;


struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int x):val(x),next(nullptr) {}
    ListNode(int x, ListNode* next):val(x),next(next) {}
};

class Solution{
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* ans = new ListNode();
        ListNode* head = ans;
        ListNode* temp = nullptr;
        int carry = 0;
        while(l1!=nullptr || l2!=nullptr){
            int curr = 0;
            if(l1!=nullptr){
                curr+=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr){
                curr+=l2->val;
                l2=l2->next;
            }
            int val = curr + carry;
            ans->val = val%10;
            carry = val/10;
            temp = ans;
            ans->next = new ListNode();
            ans = ans->next;
        }
        if(carry>0){
            ans->val = carry;
            return head;
        }
        temp->next = nullptr;
        return head;    
    }
};