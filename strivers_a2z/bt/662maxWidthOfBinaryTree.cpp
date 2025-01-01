#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-width-of-binary-tree/

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
    void traversein(TreeNode* node, pair<int,int> p, unordered_map<int,pair<int,int>> &mp){
        if(!node) return;
        mp[p.first].first = max(mp[p.first].second, p.second);
        mp[p.first].second = min(mp[p.first].second, p.second);
        traversein(node->left, {p.first+1,p.second+1}, mp);
        traversein(node->right, {p.first+1,p.second-1}, mp);
    }
    int widthOfBinaryTree(TreeNode* root) {
        // pair<int,int> level, dist
        unordered_map<int,pair<int,int>> mp;
        int ans=0;
        traversein(root,{0,0},mp);
        for(auto p:mp){
            ans = max(ans,p.second.first-p.second.second);
        }
        return ans;
    }
};

int main(){
    return 0;
}