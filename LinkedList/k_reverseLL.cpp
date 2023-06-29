// reverse linked list in groups of k
// given a list [1,2,3,4,5,6]
// for k=2, ans would be [2,1,4,3,6,5]
// for k=3, ans would be [3,2,1,6,5,4]
// and so on

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr){}
    Node(int x): val(x), next(nullptr){}
    Node(int x, Node* ptr): val(x), next(ptr){}
};

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

int getLength(Node* &head){
    Node* temp = head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

Node* Kreverse(Node* &head, int k){ 
    if(head == NULL || head->next == NULL){
        return head;
    }
    int i=0;
    Node* node = head;
    head = head->next;
    node->next = NULL;
    i++; 
    //cout << i;
    Node* temp;
    while(i<k){
        temp = head->next;
        head->next = node;
        node = head;
        head = temp;
        i++;
        //cout<< i;
    }
    // node is the new head
    //cout << node->val;
    print(node);
    cout << head->val;
    cout << head->next->val << endl;
    Node* tail = node;
    while(tail->next != NULL){
        tail = tail->next;
    }
    if(head != NULL){
        int x = getLength(head);
        if (x<k){
            tail->next = head;
            return node;
        }
        tail->next = Kreverse(head,k);
    }
    return node;

}

int main(){
    Node* node = new Node;
    Node* head = node;
    Node* tail = node;

    int n;
    cout << "Enter number of nodes : ";
    cin >> n;
    int x;
    cout << "Enter values : ";
    cin >> head->val;
    for (int i=1;i<n;i++){
        cin >> x;
        InsertAtTail(tail, x);
    }

    print(head);

    cout << "Enter value of k : ";
    int k;
    cin >> k;

    Node* h = Kreverse(head,k);
    print(h);

    return 0;
}