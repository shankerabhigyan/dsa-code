// https://practice.geeksforgeeks.org/problems/construct-tree-1/1
// Given 2 Arrays of Inorder and preorder traversal. The tree can contain duplicate elements. Construct a tree and print the Postorder traversal. 
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

node* buildTree(int in[], int pre[], int n){
    if(n==0){
        return NULL;
    }
    int p = pre[0];
    node* root = new node(p);
    int leftSize = 0;
    for(int i=0;i<n;i++){
        if(in[i]==p){
            leftSize = i;
            break;
        }
    }
    int rightSize = n-leftSize-1;

    int leftIn[leftSize];
    int rightIn[rightSize];
    int leftPre[leftSize];
    int rightPre[rightSize];

    for(int i=0;i<leftSize;i++){
        leftIn[i] = in[i];
        leftPre[i] = pre[i+1];
    }
    for(int i=0;i<rightSize;i++){
        rightIn[i] = in[i+leftSize+1];
        rightPre[i] = pre[i+leftSize+1];
    }

    root->left = buildTree(leftIn, leftPre, leftSize);
    root->right = buildTree(rightIn, rightPre, rightSize);

    return root;
}

int main();
    int size;
    cin >> size;
    int in = new int[size];
    int pre = new int[size];

    cout << "Enter inorder elements: ";
    for(int i=0;i<size;i++){
        cin >> in[i];
    }

    cout << "Enter preorder elements";
    for(int i=0;i<size;i++){
        cin >> pre[i];
    }

    return 0;
}