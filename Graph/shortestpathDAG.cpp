#include<bits/stdc++.h>
using namespace std;

// the graph is a weightes DAG graph

// https://www.codingninjas.com/studio/library/shortest-path-in-a-directed-acyclic-graph

#define INF INT_MAX
unordered_map<int,list<pair<int,int>>> adj;

void getAdjList(vector<pair<int,pair<int,int>>> &edges){ // for edge 1->3 with wt. 7 : {1,{3,7}}
    for(auto edge:edges){
        int x = edge.first;
        int y = edge.second.first;
        int w = edge.second.second;
        adj[x].push_back({y,w});
    }
}

void dfs(stack<int> &s, vector<bool> &visited, int i){
    visited[i] = true;
    for(auto p: adj[i]){
        if(!visited[p.first]){
            dfs(s,visited,p.first);
        }
    }
    s.push(i);
    return;
}

vector<int> topologicalSort(vector<pair<int,pair<int,int>>> &edges, int v){
    stack<int>s;
    vector<bool> visited(v);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(s,visited,i);
        }
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

vector<int> shortestPath(vector<pair<int,pair<int,int>>> &edges, int v, int s){
    vector<int> topo = topologicalSort(edges,v);
    vector<int> dist(v,INF);
    dist[s] = 0;
    for(int i=0;i<v;i++){
        int el = topo[i];
        if(dist[el]!=INF){
            for(auto p:adj[el]){
                int x = p.first;
                int w = p.second;
                dist[x] = min(dist[x],dist[el]+w);
            }
        }
    }
    return dist;
}

int main(){
    //vector<pair<int,pair<int,int>>> edges = {{0,{1,5}}, {0,{2,3}}, {1,{3,6}}, {1,{2,2}}, {2,{4,4}}, {2,{5,2}}, {2,{3,7}}, {3,{4,-1}}, {4,{5,-2}}};
    //int v = 6;
    vector<pair<int,pair<int,int>>> edges = {{0,{1,3}}, {0,{2,6}}, {1,{2,4}}, {1,{3,4}}, {1,{4,11}}, {2,{3,8}}, {2,{6,11}}, {3,{4,-4}}, {3,{5,5}}, {3,{6,2}}, {4,{7,9}}, {5,{7,1}}, {6,{7,2}}};
    int v = 8;
    getAdjList(edges);
    int s;
    cin >> s;
    vector<int> ans = shortestPath(edges,v,s);
    for(auto x:ans){
        if(x==INT_MAX){
            cout << "INF" << " ";
        }
        else{
            cout << x << " ";
        }
    }
    cout << endl;
    return 0;
}