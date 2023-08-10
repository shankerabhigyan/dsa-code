#include<bits/stdc++.h>
using namespace std;

void getAdjList(unordered_map<int, list<pair<int,int>>> &adj, vector<pair<pair<int,int>,int>> &g){
    for(auto v:g){
        int a = v.first.first;
        int b = v.first.second;
        int w = v.second;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
}

vector<pair<pair<int,int>,int>> primsMST(int n, int m, vector<pair<pair<int,int>,int>> &g){
    vector<int> parent(n+1,-1);
    vector<bool> mst(n+1,false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> key(n+1,INT_MAX);
    unordered_map<int, list<pair<int,int>>> adj;
    getAdjList(adj,g);

    parent[1] = -1;
    key[1] = 0;
    pq.push({0,1});

    while(!pq.empty()) {
        int node = pq.top().second;
        pq.pop();
        mst[node] = true;
        for(auto p:adj[node]){
            int x = p.first;
            int w = p.second;
            if(!mst[x] && key[x]>w){
                pq.push({w,x});
                key[x] = w;
                parent[x] = node;
            }
        }
    }   

    vector<pair<pair<int,int>,int>> ans;
    for(int i=2;i<=n;i++){
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;
}