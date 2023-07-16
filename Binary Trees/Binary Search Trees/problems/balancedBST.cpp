//https://www.codingninjas.com/studio/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0
#include <bits/stdc++.h>
using namespace std;

struct node{
    int key;
    node* left;
    node* right;
    node(int val):key(val),left(nullptr),right(nullptr){}
};

void insert(node* &root,int key){
    if(root==NULL){
        root = new node(key);
    }
    if(key<root->key){
        insert(root->left,key);
    }
    else if(key>root->key){
        insert(root->right, key);
    }
}

void inorder(node* root, vector<int> &v){
    if(root==NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->key);
    inorder(root->right,v);
}

void balance(node* &root, vector<int> v){
    if(v.size()==0){
        return;
    }
    insert(root,v[v.size()/2]);
    vector<int> v1(v.begin(),v.begin()+v.size()/2);
    vector<int> v2(v.begin()+v.size()/2+1,v.end());
    balance(root,v1);
    balance(root,v2);
}

node* balancedBST(node* root){
    node* head = checkImbalance(root);
    vector<int> v;
    inorder(root,v);
    node* head = NULL;
    balance(head,v);
    return head;
}

void preorderdisplay(node* root){
    if(root==NULL){
        return;
    }
    cout << root->key << " ";
    preorderdisplay(root->left);
    preorderdisplay(root->right);
}


int main(){
    node* root = NULL;
    insert(root,10);
    insert(root,8);
    insert(root,4);
    insert(root,2);
    insert(root,12);
    insert(root,16);
    insert(root,20);
    // root is the root of an unbalanced tree with left and right subtrees both skewed
    node* head = balancedBST(root);
    preorderdisplay(head);
    cout << endl;
    return 0;
}