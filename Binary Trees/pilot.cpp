#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* right;
    node* left;
    node(int val): val(val), right(nullptr), left(nullptr){}
};

node* buildTree(node* root, int depth){
    cout<< " enter data : " ;
    int data;
    cin >> data;
    root  = new node(data);
    if(data == -1){
        return NULL;
    }
    depth++;
    cout << "for left node of "<< data;
    root->left = buildTree(root->left,depth);
    cout << "for right node of " << data ;
    root->right = buildTree(root->right,depth);
    return root;
}

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

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    int n=0;
    int count=0;
    while(!q.empty()){
        node* temp = q.front();
        cout << temp->val << " ";
        count++;
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        if(count == pow(2,n)){
            cout << endl;
            n++;
            count=0;
        }
    }
    cout << endl;
    return;
}

void inOrderTraverse(node* root){ // LNR
    if(!root){
        return;
    }
    inOrderTraverse(root->left);
    cout << root->val << " ";
    inOrderTraverse(root->right);
    return;
}

void preOrderTraverse(node* root){ // NLR
    if(!root){
        return;
    }
    cout << root->val << " ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
    return;
}

void postOrderTraverse(node* root){ //LRN
    if(!root){
        return;
    }
    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    cout << root->val << " ";
    return;
}

int main(){
    //node* root = NULL;
    // 5 6 8 -1 -1 7 -1 -1 1 0 -1 -1 2 -1 -1
    //root = buildTree(root,0);
    node* root = buildFromLevelOrder();
    cout << endl;
    levelOrderTraversal(root);
    inOrderTraverse(root);
    cout << endl;
    preOrderTraverse(root);
    cout << endl;
    postOrderTraverse(root);
    cout << endl;
    return 0;
}