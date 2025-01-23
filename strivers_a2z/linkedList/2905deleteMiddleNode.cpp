// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==nullptr)return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            temp = slow;
            slow=slow->next;
        }
        temp->next = slow->next;
        delete slow;
        return head;
    }
};

int main(){
    return 0;
}