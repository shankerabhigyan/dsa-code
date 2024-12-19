#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

class Solution {
  public:
    
    void dfs(int i, vector<vector<pair<int,int>>> &adj, vector<bool> &visited, stack<int> &st){
        if(visited[i]) return;
        visited[i] = true;
        for(auto x:adj[i]){
            dfs(x.first,adj,visited,st);
        }
        st.push(i);
    }
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        stack<int> st;
        vector<bool> visited(V,false);

        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<E;i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int d = edges[i][2];
            adj[a].push_back({b,d});
        }

        for(int i=0;i<V;i++){ // topo sort
            dfs(i,adj,visited,st);
        }

        vector<int> dist(V,INT_MAX);

        while(st.top()!=0){
            dist[st.top()]=-1;
            st.pop();
        } // since all edges not reacheable from 0 will be after 0 in the topo sort
        dist[0]=0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            for(auto p:adj[top]){
                dist[p.first] = min(dist[p.first],dist[top]+p.second);
            }
        }
        return dist;
    }    
};


int main(){
    return 0;
}