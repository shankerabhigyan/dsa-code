#include<bits/stdc++.h>
using namespace std;
// data replacement is not allowed, change links instead

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(int x, Node* next): val(x), next(next) {}
};

void print(Node* node){
    if(node==NULL){
        cout << endl;
        return;
    }
    cout << node->val << " ";
    print(node->next);
}

Node* merge(Node* n1, Node* n2){
    Node* merge = new Node();
    Node* tail = merge;
    while(n1!=NULL && n2!=NULL){
        if(n1->val < n2->val){
            tail->next = n1;
            n1 = n1->next;
        }
        else{
            tail->next = n2;
            n2 = n2->next;
        }
        tail = tail->next;
    }
    while(n1!=NULL){
        tail->next = n1;
        n1 = n1->next;
        tail = tail->next;
    }
    while(n2!=NULL){
        tail->next = n2;
        n2 = n2->next;
        tail = tail->next;
    }
    
    return merge->next;
}


void MergeSort(Node* &node){
    if(node == NULL || node->next == NULL){
        return;
    }
    Node* slow = node;
    Node* fast = slow->next->next;
    while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
    }
    // this way now slow denotes the middle of the matrix
    fast = slow->next;
    slow->next = NULL;
    slow = node;
    //slow is now the first pointer of the first half and fast of the second half
    MergeSort(slow);
    MergeSort(fast);
    node = merge(slow,fast);
};

int main(){
    int n;
    cin>>n;
    Node* head = new Node();
    Node* tail = head;
    cin >> tail->val;
    int x;
    for(int i=1; i<n;i++){
        cin >> x;
        tail->next = new Node(x);
        tail = tail->next;
    }
    cout << endl << "Original LL: ";
    print(head);

    MergeSort(head);
    cout << endl << "Sorted LL: ";
    print(head);

    return 0;
}