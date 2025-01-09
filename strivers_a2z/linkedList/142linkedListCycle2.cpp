#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/linked-list-cycle-ii/description/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
    }
};

int main(){
    return 0;
}