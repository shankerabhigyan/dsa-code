// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1
// Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val):data(val),left(nullptr),right(nullptr){}
};

bool isCBT(Node* root, int i, int nodecount){
    if(!root){
        return true;
    }

    if(i>=nodecount){
        return false;
    }

    return isCBT(root->left, 2*i+1, nodecount) && isCBT(root->right, 2*i+2, nodecount);
}

bool isMaxHeap(Node* tree){
    if(!tree || (!tree->left && !tree->right)){
        return true;
    }

    if(tree->right && tree->data < tree->right->data){
        return false;
    }

    if(tree->left && tree->data < tree->left->data){
        return false;
    }

    return isMaxHeap(tree->left) && isMaxHeap(tree->right);
}

bool solve(Node* tree){
    int nodecount = 0;
    queue<Node*> q;
    q.push(tree);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        nodecount++;
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
    }

    return isCBT(tree, 0, nodecount) && isMaxHeap(tree);
}

int main(){
    Node* n = new Node(5);
    n->left = new Node(2);
    n->right = new Node(3);

    cout << solve(n) << endl;

    Node* h = new Node(10);
    h->left = new Node(20);
    h->right = new Node(30);
    h->left->left = new Node(40);
    h->left->right = new Node(60);
    cout << solve(h) << endl;
    return 0;
}