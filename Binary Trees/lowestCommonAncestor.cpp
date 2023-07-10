// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
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

node* lca(node* root, int n1, int n2){ // better solution
    if(root==NULL){
        return NULL;
    }
    
    if(root->val == n1 || root->val == n2){
        return root;
    }

    node* left = lca(root->left, n1, n2);
    node* right = lca(root->right, n1, n2);

    if(left && right){
        return root;
    }

    else if(!left && right){
        return right;
    }

    else if(!right && left){
        return left;
    }

    else{
        return NULL;
    }
}

int main(){
    int n1,n2;
    cin >> n1 >> n2;
    node* root = buildFromLevelOrder();
    node* c = lca(root,n1,n2);
    cout << c->val << endl;

    return 0;
}