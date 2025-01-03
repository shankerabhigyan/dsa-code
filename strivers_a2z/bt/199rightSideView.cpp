#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-tree-right-side-view/description/

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
    void traversein(TreeNode* node, map<int,int>&mp, int depth){
        if(node==nullptr) return;
        traversein(node->left,mp,depth+1);
        mp[depth] = node->val;
        traversein(node->right,mp,depth+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int,int> mp;
        traversein(root,mp,0);
        vector<int>ans;
        for(auto &p:mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};

int main(){
    return 0;
}