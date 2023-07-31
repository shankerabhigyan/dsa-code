// https://www.codingninjas.com/studio/problems/dfs-traversal_630462?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
using namespace std;

unordered_map<int,set<int,greater<int>>> getAdjList(vector<vector<int>> edges){
    unordered_map<int,set<int,greater<int>>> adj;
    for(auto edge:edges){
        int x = edge[0];
        int y = edge[1];
        adj[x].insert(y);
        adj[y].insert(x);
    }
    return adj;
}

vector<vector<int>> DFS(int V, int E, vector<vector<int>> edges){
    stack<int> s;
    unordered_map<int,bool> visited;
    unordered_map<int,set<int,greater<int>>> adj = getAdjList(edges);
    s.push(0);
    vector<vector<int>> ans;
    for(int i=0;i<V;i++){
        vector<int> temp;
        while(!s.empty()){
            int el = s.top();
            s.pop();
            temp.push_back(el);
            visited[el] = true;
            for(auto x:adj[el]){
                if(!visited[x]){
                    s.push(x);
                    visited[x] = true;
                }
            }
        }
        if(temp.size()>0){
            ans.push_back(temp);
        }
        if(!visited[i]){
            s.push(i);
        }
    }
    return ans;
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

    vector<vector<int>> dfs = DFS(vertex,edge,edges);
    for(auto x:dfs){
        for(auto y:x){
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}