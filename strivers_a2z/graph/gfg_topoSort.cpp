#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int i, vector<vector<int>>& adj, vector<bool> &visited, stack<int> &st){
        if(visited[i]) return;
        visited[i] = true;
        for(int x:adj[i]){
            dfs(x,adj,visited,st);
        }
        st.push(i);
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n,false);
        stack<int> st;
        for(int i=0;i<n;i++){
            dfs(i,adj,visited,st);
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};

int main(){
    return 0;
}