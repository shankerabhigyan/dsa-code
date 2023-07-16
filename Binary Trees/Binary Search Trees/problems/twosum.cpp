// https://www.codingninjas.com/studio/problems/two-sum-in-a-bst_1062631?leftPanelTab=0
// target O(N) time and O(H) space
#include <bits/stdc++.h>
using namespace std;

struct node{
    int key;
    node* left;
    node* right;
    node(int val):key(val),left(nullptr),right(nullptr){}
};

void inorder(node* root, vector<int> &v){
    if(node==NULL){
        return;
    }
    inorder(root->left, v);
    v.push_back(root->key);
    inorder(root->right, v);
}

/*bool twoSumBST(node* root, int target){
    vector<int> v;
    inorder(root,v);
    int i = 0;
    int j = v.size()-1;
    while(i<j){
        if(v[i]+v[j]==target){
            return true;
        }
        else if(v[i]+v[j] < target){
            i++;
        }
        else{
            j--;
        }
    }
    return false;
}*/

bool twoSumBST(node* root, target){
    if(root==NULL){
        return;
    }
    node*
}

int main(){

    return 0;
}