#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/odd-even-linked-list/description/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *a=head, *b=head->next, *temp1=head, *temp2=head->next;
        while(b!=nullptr){
            a->next = b->next;
            a = b;
            b = b->next;
        }
        while(temp1->next!=nullptr){
            temp1=temp1->next;
        }
        temp1->next = temp2;
        return head;
    }
};


int main(){
    return 0;
}