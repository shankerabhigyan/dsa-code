#include<bits/stdc++.h>
using namespace std;

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
    if(n1==NULL){
        return n2;
    }
    if(n2==NULL){
        return n1;
    }
    Node* head = NULL;
    if(n1->val < n2->val){
        head = n1;
        head->next = merge(n1->next, n2);
    }
    else{
        head = n2;
        head->next = merge(n1, n2->next);
    }
    return head;
}

Node* MergeSort(Node* node){
    if(node==NULL || node->next==NULL){
        return node;
    }
    Node* n1 = node;
    Node* n2 = node;
    while(n2!=0 && n2->next!=0){
        n1 = n1->next;
        n2 = n2->next->next;
    }
    n2 = n1->next;
    n1->next = NULL;
    n1 = node;
    n1 = MergeSort(n1);
    n2 = MergeSort(n2);
    Node* head = merge(n1, n2);
    return head;


}

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

    head = MergeSort(head);
    cout << endl << "Sorted LL: ";
    print(head);

    return 0;
}