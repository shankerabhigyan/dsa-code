// find the shortest path in an undirected fully connected graph
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> getAdjList(vector<pair<int,int>> &edges, int n){
    vector<vector<int>> adj(n+1);
    for(auto edge:edges){
        int x = edge.first;
        int y = edge.second;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    return adj;
}

vector<int> shortestPath(vector<pair<int,int>> edges, int n, int m, int s, int t){ // s: start node; t: end node
    vector<vector<int>> adj = getAdjList(edges,n);
    vector<int> ans;
    queue<int> q;
    q.push(s);
    vector<int> visited(n+1,0);
    visited[s] = 1;
    vector<int> parent(n+1,-1);
    while(!q.empty()){
        int el = q.front();
        q.pop();
        for(auto x:adj[el]){
            if(!visited[x]){
                visited[x] = 1;
                q.push(x);
                parent[x] = el;
                if(x==t){
                    q = queue<int>();
                    break;
                }
            }
        }
    }
    int temp = t;
    while(temp!=-1){
        ans.push_back(temp);
        temp = parent[temp];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    int vertex;
    int edge;
    vector<pair<int,int>> edges;

    //cout << "Enter no. of vertices and edges: ";
    cin >> vertex >> edge;

    //cout << "Enter start and end node: ";
    int s,t;
    cin >> s >> t;

    //cout << "Enter edges" << endl;
    int x,y;
    for(int i=0;i<edge;i++){
        cin >> x >> y;
        edges.push_back({x,y});
    }

    vector<int> ans = shortestPath(edges,vertex,edge,s,t);
    for(auto x:ans){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}