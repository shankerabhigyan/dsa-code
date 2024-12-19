#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        queue<pair<int,int>> q;
        vector<bool> visited(adj.size(),false);
        q.push({src,0});
        vector<int> dist(adj.size(),INT_MAX);
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            if(!visited[p.first]){
                visited[p.first] = true;
                dist[p.first] = min(dist[p.first],p.second);
                for(int x:adj[p.first]){
                    q.push({x,p.second+1});
                }
            }
        }
        for(int i=0;i<dist.size();i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        return dist;
    }
};

int main(){

    return 0;
}