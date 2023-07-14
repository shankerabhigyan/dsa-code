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

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void deleteFromBST(node* &root, int el){
    if(root==NULL){
        return;
    }
    if(el<root->key){
        deleteFromBST(root->left,el);
    }
    else if(el>root->key){
        deleteFromBST(root->right,el);
    }
    else{
        if(!root->left && !root->right){
            delete root;
            root = NULL;
        }
        else if(root->left && !root->right){
            node* temp = root;
            root = root->left;
            delete temp;
        }
        else if(!root->left && root->right){
            node* temp = root;
            root = root->right;
            delete temp;
        }
        else{
            node* temp = root->right;
            while(temp->left){
                temp = temp->left;
            }
            root->key = temp->key;
            deleteFromBST(root->right,temp->key);
        }
    }
}

int main(){
    node* root = buildBST();
    inorder(root);
    cout <<  endl;
    int x;
    cin >> x;
    deleteFromBST(root,x);
    inorder(root);
    cout <<  endl;
    return 0;
}