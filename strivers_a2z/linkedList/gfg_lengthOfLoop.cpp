#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/find-length-of-loop/1?

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) break;
        }
        if(fast==nullptr || fast->next==nullptr) return 0;
        else{
            int count = 0;
            Node* curr = slow;
            slow = slow->next;
            count++;
            while(slow!=curr){
                slow = slow->next;
                count++;
            }
            return count;
        }
    }
};


int main(){
    return 0;
}