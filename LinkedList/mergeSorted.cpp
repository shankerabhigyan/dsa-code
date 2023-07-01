#include<bits/stdc++.h>
using namespace std;

// Merge two sorted Linked Lists
// https://leetcode.com/problems/merge-two-sorted-lists/description/

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr){}
    Node(int x): val(x), next(nullptr){}
    Node(int x, Node* next): val(x), next(next){}
};

void printList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void InsertAtTail(Node* &tail, int val){
    if(tail == nullptr){
        tail = new Node(val);
    }
    else{
        Node* newNode = new Node(val);
        tail->next = newNode;
        tail = newNode;
    }
}

void InsertAtHead(Node* &head, int data){
    Node* node = new Node(data);
    node->next = head;
    head = node;
}

void Insert(Node* &head, Node* &tail, int n, int data){
    
    if(n<1){
        cout << "Index out of bounds" << endl;
        return;
    }

    if(n==1){
        InsertAtHead(head,data);
        return;
    }
    if(n==2){
        Node* node = new Node(data);
        node->next = head->next;
        head->next = node;
        if(node->next == NULL){
            tail = node;
        }
        return;
    }
    
    Insert(head->next, tail, n-1, data);
}

Node* mergeSortedLists(Node* head1, Node* head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    Node* prev = head1;
    Node* temp = head2;
    Node* curr = prev;
    while(curr!=NULL && temp!=NULL){
        if(temp->val <= curr->val){
            Node* node = new Node(temp->val);
            if(curr == head1){
                node->next = head1;
                head1 = node;
                prev = head1;
            }
            else{
                node->next = curr;
                prev->next = node;
                prev = node;
            }
            temp = temp->next;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
    if(temp!=NULL){
        prev->next = temp;
    }

    return head1;


}

int main(){
    int x,y;
    cin >> x >> y;
    // list 1
    cout << "Enter the elements of the first list: ";
    Node* head1 = new Node();
    cin >> head1->val;
    Node* tail1 = head1;
    for(int i=1; i<x; i++){
        int val;
        cin >> val;
        InsertAtTail(tail1, val);
    }
    // list 2
    cout << "Enter the elements of the second list: ";
    Node* head2 = new Node();
    cin >> head2->val;
    Node* tail2 = head2;
    for(int i=1; i<y; i++){
        int val;
        cin >> val;
        InsertAtTail(tail2, val);
    }

    Node* head = mergeSortedLists(head1, head2);
    printList(head);


    return 0;
}