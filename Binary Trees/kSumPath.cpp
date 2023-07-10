// https://practice.geeksforgeeks.org/problems/k-sum-paths/1
// Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
// A path may start from any node and end at any node in the downward direction.
#include<bits/stdc++.h>
using namespace std;
#define ll long long

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
        if(data!=0){
            left = new node(data);
        }
        else{
            left = NULL;
        }
        cout << "Enter right node value for " << temp->val << " : ";
        cin >> data;
        if(data!=0){
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
// 0 - NULL

void kSum(node* root, int k, ll sum, unordered_map<ll,int> &m, int &count){
    if(!root){
        return;
    }
    
    if(sum+root->val == k){
        count++;
    }
    
    count+=m[sum+root->val-k];
    m[sum+root->val]++;

    kSum(root->left, k, sum+root->val, m, count);
    kSum(root->right, k, sum+root->val, m, count);

    m[sum+root->val]--;
    return;
}

int sumK(node* root, int k){
    int count=0;
    unordered_map<ll,int> m;
    kSum(root,k,0,m,count);
    return count;
}

int main(){
    int sum;
    cin >> sum;
    node* root = buildFromLevelOrder();
    cout << sumK(root, sum) << endl;
    return 0;
}