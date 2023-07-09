// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
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

vector<int> vertical(node* root){ // O(n)
    queue<pair<node*,int>> q;
    q.push({root,0});
    map<int,vector<int>> m; // vertical-order, vector of values in level-order for that vertical-order
    pair<int,int> p = {0,0};
    
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            node* curr = q.front().first;
            int v = q.front().second;
            p.first = max(p.first,v);
            p.second = min(p.second,v);
            m[v].push_back(curr->val);
            if(curr->left!=NULL){
                q.push({curr->left,v+1});
            }
            if(curr->right!=NULL){
                q.push({curr->right,v-1});
            }
            q.pop();
        }
    }
    vector<int> v;
    for(int i = p.first;i>=p.second;i--){
        for(auto x:m[i]){
            v.push_back(x);
        }
    }
    return v;
}


int main(){
    node* root = buildFromLevelOrder();
    vector<int> v = vertical(root);
    for(auto x:v){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}