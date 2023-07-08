// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
// A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 
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

int balance(node* root){ // O(n) since we are traversing each node once
    if(root==NULL){
        return 0;
    }
    int left = balance(root->left);
    int right = balance(root->right);

    if(left == -1 || right == -1){
        return -1;
    }

    if(left-right>1 || left-right<-1){
        return -1;
    }
    return max(left,right)+1;
}

bool isBalanced(node* root){
    if(root==NULL){
        return true;
    }
    int ans = balance(root);
    if(ans==-1){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    node* root = buildFromLevelOrder();
    bool b = isBalanced(root);
    cout << endl << b << endl;
    return 0;
}