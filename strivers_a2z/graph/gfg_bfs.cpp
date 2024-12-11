// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        queue<int> q;
        vector<bool> vis(adj.size(), false);
        q.push(0);
        vector<int> ans;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            if(!vis[x]){
                vis[x]=true;
                ans.push_back(x);
                for(int y:adj[x]){
                    if(!vis[y]){
                        q.push(y);
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    
    return 0;
}