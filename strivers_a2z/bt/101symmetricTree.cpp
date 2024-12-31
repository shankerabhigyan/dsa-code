#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/symmetric-tree/description/
// 101 Symmetric Tree

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
    bool isSymmetric(TreeNode* root) {
        
    }
};

int main(){
    return 0;
}