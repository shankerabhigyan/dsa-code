// detecting cycles in an undirected graph
#include<bits/stdc++.h>
using namespace std;

unordered_map<int,list<int>> getAdjList(vector<pair<int,int>> edges){
    unordered_map<int,list<int>> adj;
    for(auto edge:edges){
        int x = edge.first;
        int y = edge.second;
        adj[x].push_back(y);
    }
    return adj;
}
// using BFS
int detectCycleInDirectedGraph(int n, vector<pair<int,int>> &edges){
    unordered_map<int,list<int>> adj = getAdjList(edges);
    unordered_map<int,bool> visited;
    queue<int> s;
    s.push(1);
    for(int i=1;i<=n;i++){
        unordered_map<int,bool> tvisited;
        while(!s.empty()){
            int el = s.front();
            s.pop();
            visited[el] = true;
            tvisited[el] = true;
            for(auto x:adj[el]){
                if(tvisited[x]){
                    return 1;
                }
                s.push(x);
            }
        }
        if(!visited[i]){
            s.push(i);
        }
    }
    return 0;
}

// using DFS
void recurse(int v, unordered_map<int,bool> visited, unordered_map<int,bool> &global, unordered_map<int,list<int>> &adj, bool &cyclic){
    //cout << "v : "<< v << endl;
    visited[v] = true;
    global[v] = true;
    for(auto x:adj[v]){
        if(visited[x]){
            cyclic = true;
            return;
        }
        else{
            recurse(x,visited,global,adj,cyclic);
        }
    }
}

int detectCycleInDirectedGraph2(int n, vector<pair<int,int>> &edges){
    unordered_map<int,list<int>> adj = getAdjList(edges);
    bool cyclic = false;
    unordered_map<int,bool> visited;
    unordered_map<int,bool> global;
    for(int i=1;i<=n;i++){
        if(!global[i]){
            //cout << "here" << endl;
            recurse(i,visited,global,adj,cyclic);
            if(cyclic){
                return cyclic;
            }
        }
    }
    return cyclic;
}

int main(){
    int n;
    cin >> n;
    int e;
    cin >> e;
    vector<pair<int,int>> edges;
    for(int i=0;i<e;i++){
        int x,y;
        cin >> x >> y;
        edges.push_back({x,y});
    }
    cout << detectCycleInDirectedGraph2(n,edges) << endl;
    return 0;
}