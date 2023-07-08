// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
// find diameter of binary tree -- no. of nodes b/w the longest path in a tree
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

int diameter(node* root){
    
}

int main(){
    node* root = buildFromLevelOrder();
    // 1 2 14 3 5 -1 15 4 6 -1 11 -1 -1 -1 -1 7 -1 10 12 8 9 -1 -1 -1 13 -1 -1 -1 -1 -1 -1
    int dia = diameter(root);
    cout << endl << dia << endl;
    return 0;
}