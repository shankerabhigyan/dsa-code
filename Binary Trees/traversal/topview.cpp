// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
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

vector<int> topview(node* root){
    queue<pair<node*,int>> q;
    q.push({root,0});
    map<int,int> m;
    pair<int,int> p = {0,0};
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            node* curr = q.front().first;
            int v = q.front().second;
            p.first = max(p.first,v);
            p.second = min(p.second,v);
            if(m[v]==0){ // for the bottom view problem, just get rid of the if condition here
                m[v] = curr->val;
            }
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
    for(int i = p.first; i>=p.second; i--){
        v.push_back(m[i]);
    }
    return v;
}

int main(){
    node* root = buildFromLevelOrder();
    vector<int> tv = topview(root);

    for(auto x:tv){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}