#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

class Solution {
  public:
    // Function to detect cycle in an undirected graph. 
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n,false);
        vector<int> parent(n,-1);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    if(!visited[node]){
                        visited[node] = true;
                        for(int x:adj[node]){
                            if(visited[x] && node!=parent[x] && parent[x]!=-1) return true;
                            parent[x] = node;
                            q.push(x);
                        }
                    }
                }
            }
        }
        return false;
    }
};
