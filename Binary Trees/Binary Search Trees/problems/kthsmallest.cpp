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


int kthSmallest(node* root, int &k){
    if(root==NULL){
        return -1;
    }
    
    int left = kthSmallest(root->left, k);
    if(left!=-1){
        return left;
    }
    k--;
    if(k==0){ 
        return root->key;
    }
    int right = kthSmallest(root->right,k);
    return right;
    
}

int main(){
    node* root = buildBST();
    int k;
    cin >> k;
    cout << kthSmallest(root,k) << endl;
    return 0;
}