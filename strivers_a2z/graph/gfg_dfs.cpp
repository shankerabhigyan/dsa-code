#include<bitd/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
public:

    void dfs(vector<vector<int>> &adj, vector<int>&visited, vector<int>&ans, int s){
        visited[s] = 1;
        ans.push_back(s);
        for(int i:adj[s]){
            if(!visited[i]) dfs(adj,visited,ans,i);
        }
    }

    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        vector<int> visited(adj.size(),0);
        vector<int> ans;
        dfs(adj,visited,0);
        return ans;
    }
};