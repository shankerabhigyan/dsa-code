#include<bits/stdc++.h>
using namespace std;

void getAdjList(unordered_map<int,list<pair<int,int>>> &adj, vector<vector<int>> &vec){
    for(auto v:vec){
        int a = v[0];
        int b = v[1];
        int w = v[2];
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
}

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source){
    unordered_map<int,list<pair<int,int>>> adj; 
    getAdjList(adj,vec);
    set<pair<int,int>> pq; 
    pq.insert({0,source});
    vector<int> dist(vertices,INT_MAX);
    set<int> visited;
    dist[source] = 0;

    while(!pq.empty()){
        int node = pq.begin()->second;
        int nodeDist = pq.begin()->first;
        pq.erase(pq.begin());
        if(visited.find(node)!=visited.end()) continue;
        visited.insert(node);
        for(auto p:adj[node]){
            int x = p.first;
            int w = p.second;
            if(dist[x]>nodeDist+w){
                pq.erase({dist[x],x});
                dist[x] = nodeDist+w;
                pq.insert({dist[x],x});
            }
        }
    }
    return dist;
}