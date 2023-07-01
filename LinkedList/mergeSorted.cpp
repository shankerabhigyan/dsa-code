#include<bits/stdc++.h>
using namespace std;

// Merge two sorted Linked Lists

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

void mergeSortedLists(Node* &head1, Node* &head2){
    
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



    return 0;
}