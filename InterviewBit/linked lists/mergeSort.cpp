#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

ListNode* getMiddle(ListNode* head){
    if(head==nullptr) return head;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next!=nullptr && fast->next->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* merge(ListNode* lefthead, ListNode* righthead){
    if(lefthead==nullptr) return righthead;
    if(righthead==nullptr) return lefthead;
    if(lefthead->val>righthead->val) swap(lefthead,righthead);
    ListNode* result = lefthead;
    while(lefthead!=nullptr && righthead!=nullptr){
        ListNode* temp = nullptr;
        while(lefthead!=nullptr && lefthead->val<=righthead->val){
            temp = lefthead;
            lefthead = lefthead->next;
        }
        temp->next = righthead;
        swap(lefthead,righthead);
    }
    return result;
}

ListNode* mergeSort(ListNode* A){
    if(A==nullptr || A->next==nullptr) return A;
    ListNode* mid = getMiddle(A);
    ListNode* m1 = mid->next;
    mid->next = nullptr;
    ListNode* left = mergeSort(A);
    ListNode* right = mergeSort(m1);
    ListNode* sorted = merge(left,right);
    return sorted;
}



int main(){

    return 0;
}