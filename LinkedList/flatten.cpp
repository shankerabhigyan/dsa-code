// https://www.codingninjas.com/studio/problems/flatten-a-linked-list_1112655?source=youtube&campaign=YouTube_CodestudioLovebabbar5thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_CodestudioLovebabbar5thfeb
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* child;
    Node(): val(0), next(nullptr), child(nullptr) {}
    Node(int x): val(x), next(nullptr), child(nullptr) {}
    Node(int x, Node* next, Node* child): val(x), next(next), child(child) {}
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
}

Node* flatten(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* node = head;
    Node* merged = NULL;
    while(node!=NULL){
        merged = merge(merged, node->child);
        node = node->next;
    }
    MergeSort(head);
    merged = merge(merged, head);
    return merged;
}

int main(){
    int n;
    //cout << "Enter the number of elements: ";
    cin >> n;
    Node* head = NULL;
    Node* tail = NULL;
    for(int i=0; i<n;i++){
        int childs;
        //cout << "Enter the value of node and child nodes: ";
        cin >> childs;
        Node* node = new Node();
        Node* temp = node;
        cin >> node->val;
        for(int j=1; j<childs; j++){
            int x;
            cin >> x;
            if(j==1){
                node->child = new Node(x);
                node = node->child;
            }
            else{
                node->next = new Node(x);
                node = node->next;
            }
        }
        if(i==0){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }

    Node* merged = flatten(head);
    print(merged);
    //print(head);

    return 0;
}