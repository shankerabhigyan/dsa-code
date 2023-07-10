// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
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

void leftview(node* root, map<int,int> &m, int n){ // [depth,value]
    if(root==NULL){
        return;
    }

    if(m[n]==0){
        m[n] = root->val;
    }

    leftview(root->left,m,n+1);
    leftview(root->right,m,n+1);
    
    return;
}

vector<int> leftView(node* root){
    int n=0;
    map<int,int> m;
    leftview(root,m,n);
    vector<int> ans;
    // map 
    for(auto x:m){
        ans.push_back(x.second);
    }
    return ans;
}

int main(){
    node* root = buildFromLevelOrder();
    vector<int> lv = leftView(root);
    for(int x:lv){
        cout << x << " ";
    }
    cout <<  endl;
    return 0;
}

// sample input tree
// 1 2 7 3 4 -1 8 -1 -1 5 -1 9 -1 -1 6 -1 10 -1 -1 11 -1 12 13 -1 -1 -1 -1
// output
// 1 2 3 5 6 11 12
