// https://www.codingninjas.com/studio/problems/bridges-in-graph_893026?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
using namespace std;

void getAdjList(unordered_map<int,list<pair<int,int>>> &adj, vector<vector<int>> &edges){
    for(auto e:edges){
        int a = e[0];
        int b = e[1];
        int w = e[2];
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
}

vector<vector<int>> tarjansBridges(vector<vector<int>> &edges, int v, int e){
    unordered_map<int,list<pair<int,int>>> adj;
    getAdjList(adj,edges);
}