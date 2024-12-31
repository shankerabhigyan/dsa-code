// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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
    int recurse(TreeNode* node, int &ans){
        if(!node) return 0;
        int left = recurse(node->left,ans);
        int right = recurse(node->right,ans);
        int x = max(left,right);
        int x2 = max(node->val,node->val+x);
        ans = max(ans,max(x2,node->val+left+right));
        return x2;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        recurse(root,ans);
        return ans;
    }
};

int main(){
    return 0;
}