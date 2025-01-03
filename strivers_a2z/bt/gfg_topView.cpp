#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        if(!root) return {};
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto [node, line]= q.front();
            q.pop();
            if(mp.find(line)==mp.end()) mp[line]=node->data;
            if(node->left!=nullptr)q.push({node->left,line-1});
            if(node->right!=nullptr)q.push({node->right,line+1});
        }
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