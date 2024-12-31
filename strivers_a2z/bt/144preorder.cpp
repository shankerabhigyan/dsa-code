// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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
    void traversePRE(TreeNode* root, vector<int> &ans){
        if(root==nullptr) return;
        ans.push_back(root->val);
        traversePRE(root->left,ans);
        traversePRE(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        traversePRE(root,ans);
        return ans;
    }
};