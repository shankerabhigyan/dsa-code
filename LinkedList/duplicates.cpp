// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// https://www.codingninjas.com/studio/problems/remove-duplicates-from-unsorted-linked-list_1069331?source=youtube&campaign=YouTube_Lovebabbar29thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar29thJan
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

void removeElement(Node* prev){
    Node* temp = prev->next;
    prev->next = temp->next;
    delete temp;
}

void removeDuplicates(Node* head){ // O(n) time and O(n) space; works for sorted and unsorted both
    if(head == NULL || head->next == NULL){
        return;
    }
    unordered_set<int> m;
    Node* node = head;
    while(node != NULL){
        m.insert(node->val);
        if(node->next != NULL && m.find(node->next->val) != m.end()){
            removeElement(node);
            continue; // to avoid incrementing node since the next node is already deleted
        }
        node = node->next;        
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
    //removeDuplicatesSorted(head);
    removeDuplicates(head);
    print(head);


}