#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr){}
    Node(int x): val(x), next(nullptr){}
    Node(int x, Node* next): val(x), next(next){}

};

void print(Node* &node){
    cout << node->val << " ";
    if(node->next == NULL){
        cout << endl;
        return;
    }
    print(node->next);
}

bool checkPalindrome(Node* &head){ // 2 * O(n/2) time and O(1) space
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }
    if(fast != NULL){
        slow = slow->next; //  in case of odd length ignoring the middle element
    }
    while(slow != NULL){
        if(slow->val != prev->val){
            return false;
        }
        slow = slow->next;
        prev = prev->next;
    }
    return true;
}


int main(){
    int n;
    cin >> n;
    Node* head = new Node();
    Node* tail = head;
    cin >> head->val;
    int x;
    for (int i = 1; i < n; i++){
        cin >> x;
        Node* node = new Node(x);
        tail->next = node;
        tail = node;
    }

    cout << checkPalindrome(head) << endl;

    return 0;
}