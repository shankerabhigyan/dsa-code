// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* right;
    node* left;
    node(int val): val(val), right(nullptr), left(nullptr){}
};

node* buildTree(int in[], int post[], int n){ // Complexity: O(n^2) (worst case)
    if(n==0){
        return NULL;
    }

    int val = post[n-1];
    cout << val << " ";
    node* root = new node(val);

    int leftSize = 0;
    int rightSize =0;

    for(int i=0;i<n;i++){
        if(in[i]==val){
            leftSize = i;
            //cout << leftSize << endl;
            break;
        }
    }

    rightSize = n-leftSize-1;

    int left_in[leftSize];
    int left_post[leftSize];
    int right_in[rightsize];
    int right_post[rightSize];

    for(int i=0;i<leftSize;i++){
        left_in[i] = in[i];
        left_post[i] = post[i];
    }

    for(int i=0;i<rightSize;i++){
        right_in[i] = in[leftSize+i+1];
        right_post[i] = post[leftSize+i];
    }

    root->left = buildTree(left_in,left_post,leftSize);
    root->right = buildTree(right_in,right_post,rightSize);

    return root;
}

int main(){
    int n;
    cin >> n;
    int in[n];
    int post[n];

    for(int i=0; i<n; i++){
        cin >> in[i];
    }

    for(int i=0; i<n; i++){
        cin >> post[i];
    }

    node* root = buildTree(in,post,n);
    cout << endl;

    return 0;
}