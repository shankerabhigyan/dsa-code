// https://www.codingninjas.com/studio/problems/lca-in-a-bst_981280?leftPanelTab=0
// find lowest common ancestor
#include<bits/stdc++.h>
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

node* buildBST(){
    int data;
    cout << "Enter data : ";
    cin >> data;
    node* root = NULL;
    if(data==-1){
        return root;
    }
    while(data!=-1){
        insert(root,data);
        cin >> data;
    }
    return root;
}

node* LCA(node* root, int p, int q){
    if(!root){
        return NULL;
    }
    int key = root->key;
    
    if(key==p || key==q){
        return root;
    }

    if(p>key && q>key){
        return LCA(root->right, p, q);
    }
    if(p<key && q<key){
        return LCA(root->left, p, q);
    }

    return root;
}

int main(){
    int p,q;
    cin >> p >> q;
    node* root = buildBST();
    return 0;
}