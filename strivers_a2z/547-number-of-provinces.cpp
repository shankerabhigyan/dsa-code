#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &graph, vector<int>& visited){
    // for a single component
    stack<int> st;
    st.push(node);
    while(!st.empty()){
        int top = st.top();
        st.pop();
        visited[top] = 1;
        for(int n:graph[top]){
            if(!visited[n]){
                st.push(n);
            }
        }
    }
    return;
}

int findStronglyConnected(vector<vector<int>> isConnected){
    vector<vector<int>> graph(isConnected.size()); // adjacency list
    for(int i=0;i<isConnected.size();i++){
        for(int j=0;j<isConnected[i].size();j++){
            if(isConnected[i][j]==1 && i!=j){
                graph[i].push_back(j);
            }
        }
    }
    vector<int> visited(isConnected.size(),0);
    int count = 0;
    for(int i=0;i<isConnected.size();i++){
        if(visited[i]==0){
            dfs(i,graph,visited);
            count++;
        }
    }
    return count;
}