#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
// 103. Binary Tree Zigzag Level Order Traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(!root) return v;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            vector<int> subv;
            int t = q.size();
            for(int i=0;i<t;i++){
                TreeNode* fr = q.front();
                q.pop();
                subv.push_back(fr->val);
                if(fr->left)q.push(fr->left);
                if(fr->right)q.push(fr->right);
            }
            if(flag){
                reverse(subv.begin(),subv.end());
            }
            flag = !flag;
            v.push_back(subv);
        }
        return v;
    }
};

int main(){
    return 0;
}