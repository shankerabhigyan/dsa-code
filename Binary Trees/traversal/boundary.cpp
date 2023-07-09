// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
// left boundary nodes(including root) + leaf nodes remaining + reverse right boundary nodes(excluding root)
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

void leaf(node* root, vector<int> &v){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        v.push_back(root->val);
        return;
    }
    leaf(root->left,v);
    leaf(root->right,v);
    return;
}

void left(node* root, vector<int> &v){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }
    v.push_back(root->val);
    if(root->left==NULL){
        left(root->right,v);
    }
    else{
        left(root->left,v);
    }
    return;
}

void right(node* root, vector<int> &v){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }
    if(root->right==NULL){
        right(root->left,v);
    }
    else{
        right(root->right,v);
    }
    v.push_back(root->val);
    return;
}

vector<int> boundary(node* root){
    vector<int> v;
    v.push_back(root->val);
    left(root->left,v);
    leaf(root->left,v);
    leaf(root->right,v);
    right(root->right,v);
    
    return v;
}

int main(){
    node* root = buildFromLevelOrder();
    vector<int> v = boundary(root);
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}

// sample i/p 1:
// 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1

// sample i/p 2:
// 1 2 -1 4 9 6 5 -1 3 -1 -1 -1 -1 7 8 -1 -1 -1 -1

// (4 (10) (5 (5) (6 (7) (8 (8) (8 (11)))))) (3 (4) (1 (3) (8 (6) (11 (11) (5 (8))))))
// formatted i/p for the above tree in similar format as sample i/p 1 :

