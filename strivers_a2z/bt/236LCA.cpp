#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

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
    pair<bool,bool> traversein(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode* &ans){
        if(node==nullptr) return {false,false};
        auto left = traversein(node->left, p, q, ans);
        auto right = traversein(node->right, p, q, ans);
        pair<bool,bool> curr = {node==p||left.first||right.first,node==q||left.second||right.second};
        if(curr.first && curr.second){
            ans = node;
            return {false,false};
        }
        return curr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        traversein(root,p,q,ans);
        return ans;
    }
};

int main(){
    return 0;
}