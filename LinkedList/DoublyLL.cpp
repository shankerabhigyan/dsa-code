#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next=NULL;
    Node* previous=NULL;

    Node(int data){
        this->data = data;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

}

int getLength(Node* &head){
    Node* temp = head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void InsertAtHead(Node* &head, int value){
    Node* node = new Node(value);
    node->next = head;
    head->previous = node;
    head = node; 
}

void InsertAtTail(Node* &tail, int value){
    Node* node = new Node(value);
    node->previous = tail;
    tail->next = node;
    tail = node;
}

void deleteNode(Node* &head, Node* &tail, int pos){
    if(pos==1){
        Node* temp = head;
        head = head->next;
        head->previous = NULL;
        delete temp;
    }
    else if(pos==getLength(head)){
        Node* temp = tail;
        tail->previous->next = NULL;
        tail = tail->previous;
        delete temp;
    }
    else{
        Node* node = head;
        while(pos>1){
            node = node->next;
            pos--;
        }
        Node* prev = node->previous;
        Node* next = node->next;
        prev->next = next;
        next->previous = prev;
        delete node;
    } 
}

void Insert(Node* &head, Node* &tail, int value, int n){ // complexity O(n)
    if(head == NULL){
        Node* node = new Node(value);
        head = node;
        tail = node;
        return;
    }
    else{
        if(n<1){
            cout << "Invalid entry" << endl;
            return;
        }
        if(n==1){
            InsertAtHead(head,value);
            return;
        }
        if(n==getLength(head)+1){
            InsertAtTail(tail,value);
            return;
        }
        Node* node = head;
        while(n>1){
            node = node->next;
            n--;
        }
        Node* temp = new Node(value);
        Node* prev = node->previous;
        prev->next = temp;
        temp->previous = prev;
        temp->next = node;
        node->previous = temp;
    }

}

int main(){

    //create DLL
    Node* n = new Node(10);
    Node* head = n;
    Node* tail = n;
    int len = getLength(head);
    print(head);
    //cout << len << endl;
    InsertAtHead(head, 1);
    InsertAtHead(head,0);
    InsertAtTail(tail,15);
    InsertAtTail(tail,20);
    print(head);
    Insert(head,tail,25,1);
    print(head);
    cout << head->data << " " << tail->data << endl;

    /*cout << "Testing deletion" << endl;
    deleteNode(head,tail,5);
    print(head);
    cout << head->data << " " << tail->data << endl; 
    cout << head->previous << " " << tail->next << endl;*/

    return 0;
}