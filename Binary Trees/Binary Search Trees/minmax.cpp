#include<bits/stdc++.h>
using namespace std;
// find minimum / max value in a BST;


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

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int findmin(node* root){
    int data = -1;
    while(root!=NULL){
        data = root->key;
        root = root->left;
    }
    return data;
}

int findmax(node* root){
    int data = -1;
    while(root!=NULL){
        data = root->key;
        root = root->right;
    }
    return data;
}

int main(){
    node* root = buildBST();
    int min = findmin(root);
    int max = findmax(root);
    cout << min << " " << max << endl;
    return 0;
}