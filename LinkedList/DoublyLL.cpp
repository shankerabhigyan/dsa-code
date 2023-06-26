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

int main(){

    //create DLL
    Node* n = new Node(10);
    Node* head = n;
    int len = getLength(head);
    print(head);
    cout << len << endl;

    return 0;
}