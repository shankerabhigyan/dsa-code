// https://www.codingninjas.com/studio/problems/validate-bst_799483?leftPanelTab=0
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

// APPROACH 1 : 
void inorder(node* root, vector<int> &v){
    if(root==NULL){
        return;
    }
    inorder(root->left,v);
    //cout << root->key << " ";
    v.push_back(root->key);
    inorder(root->right,v);
}

bool validateBST(node* root){
    if(root == NULL){
        return true;
    }

    vector<int> v;
    inorder(root,v);
    bool flag = true;
    for(int i=0; i<v.size()-1;i++){
        if(v[i]>v[i+1]){
            flag = false;
            break;
        }
    }
    return flag;

}

// APPROACH 2 : (optimised) 
bool validateBST_(node* root, int max, int min){
    if(root == NULL){
        return true;
    }
    
    if(root->left){
        if(root->key < root->left->key){
            return false;
        }
    }

    if(root->right){
        if(root->key > root->right->key){
            return false
        }
    }

    if(root->key > max || root->key < min){
        return false;
    }
    
    return validateBST_(root->left, root->key, min) && validateBST_(root->right, max, root->key);
}

int main(){
    node* root = buildBST();
    cout << validateBST(root) << endl;

    return 0;
}