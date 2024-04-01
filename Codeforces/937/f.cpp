/*
Find the minimum height of a rooted tree†
 with a+b+c
 vertices that satisfies the following conditions:

a
 vertices have exactly 2
 children,
b
 vertices have exactly 1
 child, and
c
 vertices have exactly 0
 children.
If no such tree exists, you should report it.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* left;
    Node* right;
};

int findHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int getMinHeight(int a, int b, int c){
    queue<Node*> q;
    Node* root = new Node();
    if(a>0){
        a--;
        root->left = new Node();
        root->right = new Node();
        q.push(root->left);
        q.push(root->right);
    }
    else if(b>0){
        b--;
        root->left = new Node();
        q.push(root->left);
    }
    else if(c>0){
        c--;
    }
    else{
        return -1;
    } // a = 0, b = 0, c = 0

    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(a>0){
            a--;
            node->left = new Node();
            node->right = new Node();
            q.push(node->left);
            q.push(node->right);
        }
        else if(b>0){
            b--;
            node->left = new Node();
            q.push(node->left);
        }
        else if(c>0){
            c--;
        }
        else{
            return -1;
        }
    }
    int height = findHeight(root);
    if(a==0 && b==0 && c==0){
        return height-1;
    }
    return -1;
}

int main(){
    int testcases;
    cin >> testcases;
    while(testcases--){
        int a,b,c;
        cin >> a >> b >> c;
        cout << getMinHeight(a, b, c) << endl;
    }
    return 0;
}