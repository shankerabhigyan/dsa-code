// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// REMOVE DUPLICATES FROM SORTED AND UNSORTED LINKED LIST

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(NULL){}
    Node(int x): val(x), next(NULL){}
    Node(int x, Node* ptr): val(x), next(ptr){} 
};

void InsertAtTail(Node* &tail,  int val){
    Node* node = new Node(val);
    tail->next = node;
    tail = node;
}

void print(Node* &node){
    cout << node->val << " ";
    if(node->next == NULL){
        cout << endl;
        return;
    }
    print(node->next);
}

void removeDuplicatesSorted(Node* head){
    if(head == NULL || head->next == NULL){
        return;
    }
    Node* node = head->next;
    Node* temp = head;
    while(node != NULL){
        if(node->val == temp->val){
            temp->next = node->next;
            delete node;
            node = temp->next;
        }
        else{
            temp = node;
            node = node->next;
        }
    }
}

int main(){
    int n;
    Node* node = new Node();
    Node* head = node;
    Node* tail = node;
    cin >> n;
    cin >> node->val;
    int x;
    while(n>1){
        cin >> x;
        InsertAtTail(tail, x);
        n--;
    }
    //print(head);
    removeDuplicatesSorted(head);
    print(head);


}