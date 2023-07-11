// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
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

pair<int,int> adjSum(node* root, pair<int,int> p){ // {include_current, exclude_current}
    if(root==NULL){
        return {0,0};
    }
    pair<int,int> left = adjSum(root->left, p);
    pair<int,int> right = adjSum(root->right, p);

    // including current node
    int first = left.second + right.second + root->val;

    // excluding current node
    int second = max(left.first,left.second) + max(right.first,right.second);

    return {first,second};
}



int getMaxSum(node* root){
    pair<int,int> p = adjSum(root,p);
    return max(p.first,p.second);
}

int main(){
    node* root = buildFromLevelOrder();
    cout << getMaxSum(root) << endl;
}

