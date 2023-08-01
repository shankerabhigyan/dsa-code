// kahn's algorithm for topological sort
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

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e){
    vector<list<int>> adj = getAdjList(edges,v);
    
    vector<int> indegree(v,0);
    for(int i=0;i<e;i++){
        indegree[edges[i][1]]++;
    }
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> ans;
    int count;
    while(!q.empty()){
        int el = q.front();
        ans.push_back(el);
        q.pop();
        for(int x:adj[el]){
            indegree[x]--;
            count++;
            if(indegree[x]==0){
                q.push(x);
            }
        }
    }
    return ans;
}

int main(){

    return 0;
}