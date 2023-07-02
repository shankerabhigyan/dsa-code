// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
// a linked list is given having anext pointer and a given number of random pointers which point to a random element
// clone the linked list

#include<bits/std++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* random;
    Node(): val(0), next(nullptr), random(nullptr) {}
    Node(int x): val(x), next(nullptr), random(nullptr) {}
    Node(int x, Node* next, Node* random): val(x), next(next), random(random) {}
}

void print(Node* &node){
    cout << node->val << " ";
    if(node->next == NULL){
        cout << endl;
        return;
    }
    print(node->next);
}

Node* clone(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        Node* node = new Node(temp->val);
        node->next = temp->next;
        temp->next = node;
    }
    temp = head;
    while(temp!=NULL){
        temp->next->random = temp->random->next;
        temp = temp->next->next;
    }
    temp = head;
    Node* clone = temp->next;
    while(temp!=NULL){
        Node* temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next = temp2->next->next;
        temp = temp->next;
    }
    return clone;
}

int main(){
    Node* tail = new Node(1);
    Node* head = node;
    for (int i=2;i<=5;i++){
        Node* temp = new Node(i);
        tail->next = temp;
        tail = temp;
    }
    Node* temp = head;
    tem->random = head->next->next; // 1->3
    temp = temp->next;
    // 2-> 1
    temp->random = head;
    temp = temp->next;
    // 3-> 5
    temp->random = head->next->next->next->next;
    temp = temp->next;
    // 4-> 3
    temp->random = head->next->next;
    temp = temp->next;
    // 5-> 2
    temp->random = head->next;
    
    Node* clone = clone(head);


    return 0;
}