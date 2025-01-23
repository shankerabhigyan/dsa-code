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
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast = fast->next->next;
            if(slow==fast){
                slow = head;
                break;
            }
        }
        if(fast==nullptr || fast->next==nullptr) return nullptr;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main(){
    return 0;
}