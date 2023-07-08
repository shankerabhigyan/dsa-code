// https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
// check if trees are identical or not
// expected time : O(N)
// expected space : O(height)
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

bool isIdentical(node* root1, node* root2){
    // base case
    if(root1==NULL || root2==NULL){
        if(root1==NULL && root2==NULL){
            return true;
        }
        return false;
    }

    if(root1->val != root2->val){
        return false;
    }

    bool left = isIdentical(root1->left,root2->left);
    if(left==false){
        return false;
    }
    bool right = isIdentical(root1->right,root2->right);
    return right;
}

int main(){
    cout << "FOR TREE 1 ------>" << endl;
    node* root1 = buildFromLevelOrder();
    cout << "FOR TREE 2 ------>" << endl;
    node* root2 = buildFromLevelOrder();

    bool b = isIdentical(root1, root2);
    cout << endl << b << endl;

    return 0;
}