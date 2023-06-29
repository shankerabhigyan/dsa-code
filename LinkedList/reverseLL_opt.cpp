// more optimised solution
#include <bits/stdc++.h>
using namespace std;

struct Node{ // struct keyword is used to define a structure in C++ which is a user-defined val type.
    int val;
    Node* next;
    // constructors
    Node(): val(0), next(nullptr){}
    Node(int x):  val(x), next(nullptr){}
    Node(int x, Node* next): val(x), next(next){}
};

void InsertAtHead(Node* &head, int val){
    Node* node = new Node(val);
    node->next = head;
    head = node;
}

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
// iterative solution
void reverse(Node* &head){
    if(head == NULL || head->next == NULL){
        return;
    }

    Node* node = head;
    head = head->next;
    node->next = NULL;
    Node* temp;
    while(head->next != NULL){
        temp = head->next;
        head->next = node;
        node = head;
        head = temp;
    }
    head->next = node;
}

void reverse2(Node* &head, Node* &curr, Node* &prev){ // prev = NULL and curr = head inititally
    if(curr == NULL){
        head = prev;
        return;
    }
    Node* next = curr->next;
    reverse2(head, next, curr);
    curr->next = prev;
}

int main(){
    int n;
    cout << "Enter the number of elements in the Linked List" << endl;
    cin >> n;
    Node* node = new Node();
    Node* head = node;
    Node* tail = node;
    cout << "Enter unique elements of the Linked List" << endl;
    cin >> node->val;
    for (int i = 1; i < n; i++){
        int x;
        cin >> x;
        InsertAtTail(tail, x);
    }
    cout << "head: " << head->val << endl;
    cout << endl;

    reverse(head);

    // method 2 : recursive
    /*Node* prev = NULL;
    Node* curr = head;
    reverse2(head, curr, prev);*/ 

    print(head);
    cout << "head: " << head->val << endl;
    cout << endl;


    return 0;
}