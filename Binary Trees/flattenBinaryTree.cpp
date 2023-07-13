// uses morris traversal
// https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
// https://www.youtube.com/watch?v=2BdY9fixMrM&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=74&ab_channel=CodeHelp-byBabbar
#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* right;
    node* left;
    node(int val): val(val), right(nullptr), left(nullptr){}
};

node* buildFromLevelOrder(){
    queue<node*> q;
    cout << "Enter root value : ";
    int data;
    cin >> data;
    node* root = new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp==NULL){
            continue;
        }
        node* left;
        node* right;

        cout << "Enter left node value for " << temp->val << " : ";
        cin >> data;
        if(data!=-1){
            left = new node(data);
        }
        else{
            left = NULL;
        }
        cout << "Enter right node value for " << temp->val << " : ";
        cin >> data;
        if(data!=-1){
            right = new node(data);
        }
        else{
            right = NULL;
        }
        temp->left = left;
        temp->right = right;
        q.push(left);
        q.push(right);
    }
    return root;
}

void display(node* root){
    if(root==NULL){
        return;
    }
    cout << root->val << " ";
    display(root->right);
}

void flatten(node* root){
    node* curr = root;
    while(curr!=NULL){
        if(!curr->left){
            curr = curr->right;
        }
        else{
            node* prev = curr->left;
            while(prev->right!=NULL && prev->right!=curr){
                prev = prev->right;
            }
            if(prev->right == NULL){
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;  
            }
        }
    }
}

int main(){
    node* root = buildFromLevelOrder();
    flatten(root);
    display(root);
    cout << endl;
    return 0;
}