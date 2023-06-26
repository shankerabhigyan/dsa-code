#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void InsertAtHead(Node* &head, int data){
    Node* node = new Node(data);
    node->next = head;
    head = node;
}

void InsertAtTail(Node* &tail,  int data){
    Node* node = new Node(data);
    tail->next = node;
    tail = node;
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

void print(Node* &node){
    cout << node->data << " ";
    if(node->next == NULL){
        cout << endl;
        return;
    }
    print(node->next);
}

void deleteNodePos(Node* &head, Node* &tail, int position){
    if(position == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *temp1 = head; // previous node
    Node *temp2 = head->next; // node to be deleted
    while(position>2){
        temp1 = temp1->next;
        temp2 = temp2->next;
        position--;
    }

    if(temp2->next == NULL){
        temp1->next = NULL;
        tail = temp1;
        delete temp2;
        return;
    }

    temp1->next = temp2->next;
    delete(temp2);
}   



int main(){
    Node* node = new Node(10); // creates a node in heap
    Node* head = node;
    Node* tail = node;
    //cout << node << " " << head << " " << tail << endl;
    //cout << head->data << endl;
    //cout << head->next << endl;
    InsertAtHead(head,5);
    InsertAtHead(head,1);
    InsertAtTail(tail,20);
    int data=15, n=5;
    Insert(head,tail,n,data);
    print(head);
    //cout << head->data << " " << tail->data<<endl;
    deleteNodePos(head,tail,1);
    print(head);
    cout << head->data << " " << tail->data<<endl;
    return 0;
}