// detecting cycles in an undirected graph
#include<bits/stdc++.h>
using namespace std;

unordered_map<int,list<int>> getAdjList(vector<vector<int>> edges){
    unordered_map<int,list<int>> adj;
    for(auto edge:edges){
        int x = edge[0];
        int y = edge[1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    return adj;
}

bool cycleDetection(vector<vector<int>>& edges, int n, int m){
    unordered_map<int,list<int>> adj = getAdjList(edges);
    unordered_map<int,bool> visited;
    bool hasCycle = false;
    unordered_map<int,int> parent;
    // if during the traversal of a graph, we encounter a node which is linked to an already visited element,
    // other than its parent, a cycle will exist.
    queue<int> q;
    q.push(1);
    for(int i=0;i<n;i++){
        while(!q.empty()){
            int el = q.front();
            q.pop();
            visited[el] = true;
            for(auto x:adj[el]){
                if(visited[x]==true && x!=parent[el]){
                    hasCycle = true;
                    return hasCycle;
                }
                else if(!visited[x]){
                    parent[x] = el;
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
        if(!visited[i]){
            q.push(i);
        }
    }
    return hasCycle;
}

int main(){
    int vertex;
    int edge;
    vector<vector<int>> edges;

    cout << "Enter no. of vertices and edges: ";
    cin >> vertex >> edge;

    cout << "Enter edges" << endl;
    int x,y;
    for(int i=0;i<edge;i++){
        cin >> x >> y;
        edges.push_back({x,y});
    }

    cout << cycleDetection(edges,vertex,edge)<< endl;;
    return 0;
}