#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* right;
    node* left;
    node(int val): val(val), right(nullptr), left(nullptr){}
};

node* buildTree(node* root){
    cout<< " enter data : " ;
    int data;
    cin >> data;
    if(data == -1){
        return NULL;
    }
    root  = new node(data);
    cout << "for left node of "<< data;
    root->left = buildTree(root->left);
    cout << "for right node of " << data ;
    root->right = buildTree(root->right);
    return root;
}

int countLeafNodes(node* root){
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    int left=0,right=0;
    if(root->left!=NULL){
        left = countLeafNodes(root->left);
    }
   if(root->right!=NULL){
        right = countLeafNodes(root->right);
   }
   return left+right;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    int count = countLeafNodes(root);
    cout << count << endl;

}