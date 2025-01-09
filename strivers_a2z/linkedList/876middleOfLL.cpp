#include<bits/stdc++.h>
using namespace std;


//https://leetcode.com/problems/middle-of-the-linked-list/description/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main(){
    return 0;
}