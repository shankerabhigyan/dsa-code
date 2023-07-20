#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val):data(val),left(nullptr),right(nullptr){}
};

void inorder(Node* root, vector<int> &v){
    if(root==NULL){
        return;
    }

    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,data);
}

void BST2MinHeap(Node* &root, vector<int> &v, int &i){
    if(root==NULL){
        return;
    }
    root->data = v[i];
    BST2MinHeap(root->right,v,++i);
    BST2MinHeap(root->right,v,++i);
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    vector<int> in;
    inorder(root,in);


    return 0;
}