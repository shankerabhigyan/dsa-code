// https://www.codingninjas.com/studio/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
using namespace std;

vector<list<int>> getAdjList(vector<vector<int>> edges, int v){
    vector<list<int>> adj(v);
    for(auto edge:edges){
        int x = edge[0];
        int y = edge[1];
        adj[x].push_back(y);
    }
    return adj;
}

void recurse(stack<int> &s, vector<bool> &visited, int i, vector<list<int>> &adj){
    visited[i] = true;
    for(auto x:adj[i]){
        if(!visited[x]){
            recurse(s,visited,x,adj);
        }
    }
    s.push(i);
    return;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e){
    stack<int> s;
    vector<bool> visited(v);
    vector<list<int>> adj = getAdjList(edges,v);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            recurse(s,visited,i,adj);
        }
    }

    // storing answer in a vector
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main(){

    return 0;
}