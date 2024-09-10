#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

pair<ListNode*, ListNode*> reverse(ListNode* h) {
    if(h->next==nullptr) return {h,h};
    ListNode* prev = nullptr;
    ListNode* curr = h;
    ListNode* tail = h;  // This will become the tail after reversal

    while (curr != nullptr) {
        ListNode* next = curr->next;  // Save next node
        curr->next = prev;            // Reverse the current node's pointer
        prev = curr;                  // Move prev to current node
        curr = next;                  // Move to the next node
    }

    return {prev, tail};
}

ListNode* reverseK(ListNode* A, int K){
    ListNode* temp = A;
    ListNode* next = A;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int i = 1;
    while(next!=nullptr){
        if(i==K){
            ListNode* t = next->next;
            next->next = nullptr;
            pair<ListNode*, ListNode*>p = reverse(temp);
            ListNode* nh = p.first;
            ListNode* nt = p.second;
            if(head==nullptr){
                head = nh;
                tail = nt;
                temp = t;
                next = t;
                i = 1;
            }
            else{
                tail->next = nh;
                tail = nt;
                temp = t;
                next = t;
                i = 1;
            }
        }
        else{
            next = next->next;
            i++;
        }
    }
    return head;
}

int main(){
    return 0;
}