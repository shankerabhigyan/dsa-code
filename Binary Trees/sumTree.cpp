// https://practice.geeksforgeeks.org/problems/sum-tree/1
// Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, 
// its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.
// An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.
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

pair<int,bool> sumTree(node* root){ // first : sum, second : checksum || Complexity : O(n)
    if(root==NULL){
        return make_pair(0,true);
    }
    if(root->left==NULL && root->right==NULL){
        return make_pair(root->val,true);
    }

    pair<int,bool> left = sumTree(root->left);
    pair<int,bool> right = sumTree(root->right);

    if(left.second==false || right.second==false || left.first+right.first != root->val){
        return make_pair(left.first+right.first+root->val,false);
    }

    return make_pair(left.first+right.first+root->val,true);
}

int main(){
    node* root = buildFromLevelOrder();
    bool b = sumTree(root).second;
    cout << endl << b << endl;
    return 0;
}

// 62 16 15 N 8 4 7 N 8 4
// input for above test case
// 62 16 15 -1 8 4 7 -1 8 4 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1