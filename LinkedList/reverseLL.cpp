// https://leetcode.com/problems/reverse-linked-list/
#include<bits/stdc++.h>
using namespace std;

struct NodeLL{ // struct keyword is used to define a structure in C++ which is a user-defined val type.
    int val;
    NodeLL* next;
    // constructors
    NodeLL(): val(0), next(nullptr){}
    NodeLL(int x):  val(x), next(nullptr){}
    NodeLL(int x, NodeLL* next): val(x), next(next){}
};

void InsertAtHead(NodeLL* &head, int val){
    NodeLL* node = new NodeLL(val);
    node->next = head;
    head = node;
}

void InsertAtTail(NodeLL* &tail,  int val){
    NodeLL* node = new NodeLL(val);
    tail->next = node;
    tail = node;
}

void print(NodeLL* &node){
    cout << node->val << " ";
    if(node->next == NULL){
        cout << endl;
        return;
    }
    print(node->next);
}

void reverse(NodeLL* &head, NodeLL* &tail, NodeLL* &head1){ 
    if(head == NULL || head->next == NULL){ // empty list
        return;
    }
    if(head == tail){ // single node
        return;
    }
    if(tail->next == NULL){ // marking the new head
        head1 = tail;
    }
    if(head->next == tail){ // swapping the last two nodes and marking the new tail [base case]
        tail->next = head;
        head->next = NULL;
        tail = head;
        head = head1;
        return;
    }
    NodeLL* node = head;
    while(node->next != tail){ // reaching the second last node
        node = node->next;
    }
    // swapping the last two nodes and marking the new tail with non NULL next
    tail->next = node;
    tail = node;
    reverse(head, tail, head1); // recursive call
}

int main(){
    int n;
    cout << "Enter the number of elements in the Linked List" << endl;
    cin >> n;
    NodeLL* node = new NodeLL();
    NodeLL* head = node;
    NodeLL* tail = node;
    cout << "Enter unique elements of the Linked List" << endl;
    cin >> node->val;
    for (int i = 1; i < n; i++){
        int x;
        cin >> x;
        InsertAtTail(tail, x);
    }
    cout << "head: " << head->val << endl;
    cout << "tail: " << tail->val << endl;
    cout << endl;
    //cout << "Linked List: ";
    //print(head);   
    NodeLL* head1 = head;
    reverse(head, tail, head1);
    cout << "Reversed Linked List: ";
    print(head1);
    cout << "new head: " << head->val << endl;
    cout << "new tail: " << tail->val << endl;
    //cout << tail->next << endl;
    return 0; 
}