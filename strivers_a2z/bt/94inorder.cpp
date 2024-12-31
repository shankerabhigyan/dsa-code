#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    void traverseIN(TreeNode* root, vector<int> &ans){
        if(root==nullptr) return;
        traverseIN(root->left,ans);
        ans.push_back(root->val);
        traverseIN(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverseIN(root,ans);
        return ans;
    }
};

int main(){
    return 0;
}