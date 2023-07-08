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

int height(node* root){
    if(root==NULL){
        return 0;   
    }
    int left,right;
    left = height(root->left);
    right = height(root->right);
    int ans = max(left,right);
    return ans+1;
}

// O(n2) solution
int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int left = diameter(root->left);
    int right = diameter(root->right);
    int h = height(root->left) + height(root->right) + 1;

    int ans = max(left,right);
    ans = max(ans,h);
    return ans;
}

// O(n) solution
pair<int,int> diameterFast(node* root){
    if(root==NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> p_left = diameterFast(root->left);
    pair<int,int> p_right = diameterFast(root->right);

    int h_left = p_left.first;
    int d_left = p_left.second;
    int d_right = p_right.second;
    int h_right = p_right.first;

    int h = h_left + h_right + 1;
    int d = max(d_left,d_right);
    return make_pair(max(h_left,h_right)+1,max(h,d));
}

int solveDiameterFast(node* root){
    pair<int,int>p = diameterFast(root);
    return p.second;
}

int main(){
    node* root = buildFromLevelOrder();
    // 1 2 14 3 5 -1 15 4 6 -1 11 -1 -1 -1 -1 7 -1 10 12 8 9 -1 -1 -1 13 -1 -1 -1 -1 -1 -1
    int dia = solveDiameterFast(root);
    cout << endl << dia << endl;
    return 0;
}