// https://www.codingninjas.com/studio/problems/search-in-bst_1402878
// search in a BST
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

bool searchBST(node* root, int el){ // TC : O(log(n)) / O(height) | SC : O(height)
    if(root==NULL){
        return false;
    }

    if(root->key == el){
        return true;
    }
    else{
        if(el>root->key){
            return searchBST(root->right,el);
        }
        else{
            return searchBST(root->left,el);
        }
    }
}

bool searchInBST(node* root, int el){ // iterative method with O(1) space complexity
    while(root!=NULL){
        if(root->key==el){
            return true;
        }
        else if(el>root->key){
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return false; 
}

int main(){
    node* root = buildBST();
    cout << "enter element to search : ";
    int x;
    cin >> x;
    cout << searchInBST(root,x) <<  endl;

    return 0;
}