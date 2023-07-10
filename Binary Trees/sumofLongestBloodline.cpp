// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
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

int vecsum(vector<int> v){
    int sum = 0;
    for(int x:v){
        sum+=x;
    }
    return sum;
}

vector<int> longestBloodline(node* root){
    if(root==NULL){
        vector<int> v;
        return v;
    }
    vector<int> left = longestBloodline(root->left);
    vector<int> right = longestBloodline(root->right);

    vector<int> v;
    v.push_back(root->val);

    if(left.size()==right.size()){
        if(vecsum(left)>=vecsum(right)){
            for(int x:left){
                v.push_back(x);
            }
        }
        else{
            for(int x : right){
                v.push_back(x);
            }
        }
    }
    else if(left.size()>right.size()){
        for(int x : left){
            v.push_back(x);
        }
    }
    else{
        for(int x : right){
            v.push_back(x);
        }
    }
    return v;
}

int longestBloodlineSum(node* root){
    vector <int> v = longestBloodline(root);
    int sum = vecsum(v);
    return sum;
}

int main(){
    node* root = buildFromLevelOrder();
    int sum = longestBloodlineSum(root);
    cout << sum << endl;
    return 0;
}