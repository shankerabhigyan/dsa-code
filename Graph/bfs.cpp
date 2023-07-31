// https://www.codingninjas.com/studio/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
using namespace std;

unordered_map<int,set<int>> getAdjList(vector<pair<int,int>> edges){
    unordered_map<int,set<int>> adj;
    for(auto edge:edges){
        int x = edge.first;
        int y = edge.second;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    return adj;
}

vector<int> BFS(int vertex, vector<pair<int,int>> edges){
    queue<int> q;
    unordered_map<int,bool> visited;
    vector<int> ans;
    unordered_map<int,set<int>> adj = getAdjList(edges); // adjacency list
    q.push(0);

    for(int i=0;i<vertex;i++){
        while(!q.empty()){
            int el = q.front();
            q.pop();
            ans.push_back(el);
            visited[el]=true;
            for(auto x:adj[el]){
                if(!visited[x]){
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
        if(!visited[i]){
            q.push(i);
        }
    }
    return ans;
}

int main(){
    int vertex;
    int edge;
    vector<pair<int,int>> edges;

    cout << "Enter no. of vertices and edges: ";
    cin >> vertex >> edge;

    cout << "Enter edges" << endl;
    int x,y;
    for(int i=0;i<edge;i++){
        cin >> x >> y;
        edges.push_back({x,y});
    }

    vector<int> ans = BFS(vertex,edges);
    for(int x:ans){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}