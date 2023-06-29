// https://leetcode.com/problems/middle-of-the-linked-list/
// in case of an even number of nodes, return the second middle node
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;

    Node(): val(0), next(nullptr){}
    Node(int x): val(x), next(nullptr){}
    Node(int x, Node* next): val(x), next(next){}
};

void InsertAtTail(Node* &tail,  int val){
    Node* node = new Node(val);
    tail->next = node;
    tail = node;
}

Node* getmiddle(Node* &head){
    Node* node = head;
    Node* node2 = head;
    while(node != NULL){
        node = node->next;
        if(node == NULL)
            break;
        node = node->next;
        node2 = node2->next;
    }
    return node2;
}

int main(){
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    Node* node = new Node();
    Node* head = node;
    Node* tail = node;
    int x;
    cout<<"Enter the nodes: ";
    cin >> head->val;
    for (int i=1; i<n; i++){
        cin >> x;
        InsertAtTail(tail, x);
    }
    Node* middle = getmiddle(head);
    cout << "Middle node: " << middle->val << endl;

    return 0;
}