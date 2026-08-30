#include<bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==nullptr || head->next==nullptr){
            return head;
        }
        int len = 0;
        ListNode* temp = head;
        while(temp->next!=nullptr && temp->next->next!=nullptr){
            temp = temp->next->next;
            len+=2;
        }
        if(temp->next!=nullptr){
            len+=2;
            temp->next->next=head;
        }
        else{
            len+=1;
            temp->next=head;
        }
        k = k%len;
        int x = len-k;
        temp = head;
        while(x>1){
            temp = temp->next;
            x--;
        }
        ListNode* newHead = temp->next;
        temp->next = nullptr;
        return newHead;
    }
};