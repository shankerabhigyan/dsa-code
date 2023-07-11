// https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
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

void printStack(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int kthAncestor(node* root, int k, int node, stack<int> s){
    if(root==NULL){
        return -1;
    }

    if(root->val == node){
        if(s.size()>=k){
            //printStack(s);
            for(int i = 1;i<k;i++){
                s.pop();
            }
            return s.top();
        }
        else{
            return -1;
        }
    }
    s.push(root->val);
    int left = kthAncestor(root->left,k,node,s);
    if(left!=-1){
        return left;
    }
    int right = kthAncestor(root->right,k,node,s);
    return max(left,right);
}

int main(){
    int n,k;
    cin >> k >> n;
    node* root = buildFromLevelOrder();
    stack<int> s;
    int a = kthAncestor(root,k,n,s);
    cout << a << endl;

    return 0;
}