// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include<bits/stdc++.h>
using namespace std;

class Solution_PQ {
  public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});
        vector<int> dist(adj.size(),INT_MAX);
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            dist[p.second] = min(dist[p.second],p.first);
            for(auto pp:adj[p.second]){
                if(dist[p.second]+pp.second<dist[pp.first]){
                    pq.push({dist[p.second]+pp.second,pp.first});
                }
            }
        }
        return dist;
    }
};

class Solution_SET {
  public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        set<pair<int,int>> st; // set stores unique values in asc order
        vector<int>dist(adj.size(),INT_MAX);

        st.insert({0,src});
        dist[src]=0;

        while(!st.empty()){
            auto it = *(st.begin());
            int d = it.first;
            int x = it.second;
            st.erase(it);
            for(auto next:adj[x]){
                int node = next.first;
                int w = next.second;
                if(d+w<dist[node]){
                    if(dist[node]!=INT_MAX){
                        st.erase({dist[node],node});
                    }
                    dist[node] = d+w;
                    st.insert({d+w, node});
                }
            }
        }
        return dist;
    }
};


int main(){

    return 0;
}
