// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
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

void diagonalTraverse(node* root, map<int,vector<int>> &m, int n){
    if(root==NULL){
        return;
    }
    m[n].push_back(root->val);

    diagonalTraverse(root->left,m,n-1);
    diagonalTraverse(root->right,m,n);

    return;
}

vector<int> diagonal(node* root){
    int n = 0;
    map<int,vector<int>> m;
    diagonalTraverse(root, m, n);
    vector<int> ans;
    // reverse the map
    for(auto it=m.rbegin();it!=m.rend();it++){
        for(int x:it->second){
            ans.push_back(x);
        }
    }
    return ans;
}

int main(){
    node* root = buildFromLevelOrder();
    vector<int> d = diagonal(root);
    for(int x:d){
        cout << x << " ";
    }
    cout <<  endl;
}