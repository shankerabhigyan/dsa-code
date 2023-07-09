// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1
// print left-to-right then right-to-left then again left-to-right ans so on
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

vector<int> zigzagTraverse(node* root){
    vector<int>v;
    if(root==NULL){
        return v;
    }
    queue<node*> q;
    q.push(root);
    int level = 0;
    while(!q.empty()){
        int size = q.size();
        vector<int> temp;
        for(int i=0;i<size;i++){
            node* curr = q.front();
            q.pop();
            temp.push_back(curr->val);
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
        if(level%2==0){
            for(int i=0;i<temp.size();i++){
                v.push_back(temp[i]);
            }
        }
        else{
            for(int i=temp.size()-1;i>=0;i--){
                v.push_back(temp[i]);
            }
        }
        level++;
    }
    return v;
}

int main(){
    node* root = buildFromLevelOrder();
    vector<int> v = zigzagTraverse(root);
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}