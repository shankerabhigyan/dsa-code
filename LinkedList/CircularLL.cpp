#include<bits/stdc++.h>
using namespace std;
// circular linked list does not have duplicate values - it is a set

class Node{
    public:
    int data;
    Node* next=NULL;

    Node(int data){
        this->data = data;
    }
};

void insertAtTail(Node* &tail, int data){
    if(tail == NULL){
        Node* n = new Node(data);
        n->next = n;
        tail = n;
        return;
    }
    Node* n = new Node(data);
    n->next = tail->next;
    tail->next = n;
    tail = n;
}

void insertNodeVal(Node* &tail, int value, int data){
    if(tail == NULL){
        Node* n = new Node(data);
        n->next = n;
        tail = n;
        return;
    }
    if(tail->data == value){
        insertAtTail(tail, data);
        return;
    }
    Node* temp = tail;
    while(temp->data != value){
        temp = temp->next;
        // we assume a valid input for now
    }
    Node* ins = new Node(data);
    ins->next = temp->next;
    temp->next = ins;
}

void deleteNodeVal(Node* &tail, int value){
    if(tail == NULL){
        cout<<"Warning : Attempt to Delete an Empty List"<<endl;
        return;
    }
    if(tail->data == value){
        if(tail->next == tail){
            delete tail; // by default, the destructor of the class is called, whcih deletes the object and frees the memory
            tail = NULL; // this is done to avoid dangling pointer (which is a pointer pointing to a deleted memory location)
            return;
        }
        Node* temp = tail;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = tail->next;
        delete tail;
        tail = temp;
        return;
    }
    Node* temp = tail;
    while(temp->next->data != value){
        temp = temp->next;
    }
    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

void display(Node* tail){
    if(tail == NULL){
        return;
    }
    int value = tail->data;
    Node* temp = tail->next;
    while(temp != tail){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<value<<" ";
    cout<<endl;
}

int main(){
    Node* n = new Node(10);
    n->next = n;
    Node* tail = n;
    display(tail);
    insertAtTail(tail, 20);
    display(tail);
    insertNodeVal(tail, 10, 30);
    display(tail);
    deleteNodeVal(tail, 20);
    display(tail);
    //cout<<tail->next->data<<endl;

    return 0;
}