// https://www.codingninjas.com/studio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0
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

void display(node* root){
    if(root==NULL){
        return;
    }
    cout << root->key << " ";
    display(root->right);
}

void inorder(node* root, vector<int> &v){
    if(root==NULL){
        return;
    }
    inorder(root->left,v);
    //cout << root->key << " ";
    v.push_back(root->key);
    inorder(root->right,v);
}

node* flattenBST(node* root){
    vector<int> v;
    inorder(root,v);
    node* head;
    node* temp;
    for(int i=0; i<v.size(); i++){
        if(i==0){
            head = new node(v[i]);
            temp = head;
        }
        else{
            temp->right = new node(v[i]);
            temp = temp->right;
        }
    }
    return head;
}

// node* flattenBSTright(node* root){}

int main(){
    node* root = buildBST();
    node* head = flattenBST(root);
    display(head);
    cout << endl;
    return 0;
}