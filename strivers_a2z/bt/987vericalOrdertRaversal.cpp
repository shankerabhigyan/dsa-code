#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

// 987. Vertical Order Traversal of a Binary Tree

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<pair<TreeNode*,pair<int,int>>>q; // node, vertical(l to r), level(top to bottom)
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>> mp; // vertical : [ level : node_val(sorted) ]
        while(!q.empty()){
            int t = q.size();
            for(int i=0;i<t;i++){
                auto [node, p] = q.front();
                q.pop();
                auto [verti, lev] = p;
                mp[verti][lev].insert(node->val);
                if(node->left) q.push({node->left, {verti-1, lev+1}});
                if(node->right) q.push({node->right, {verti+1, lev+1}});
            }
        }
        for(auto p : mp){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

int main(){
    return 0;
}