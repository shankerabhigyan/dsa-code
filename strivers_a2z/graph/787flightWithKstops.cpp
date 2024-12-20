// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

#include<bits/stdc++.h>
using namespace std;

// djikstras fails in this problem,


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>>q; // {stops, node, distance}
        q.push({0,{src,0}});
        vector<int>distance(n,INT_MAX);
        distance[src] = 0;
        vector<vector<pair<int,int>>> adj(n);
        for(auto flight:flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        while(!q.empty()){
            auto [stops, t] = q.front();
            q.pop();
            auto [node, dist] = t;
            if(node==dst){
                distance[node]=min(distance[node],dist);
                continue;
            }
            for(auto nei:adj[node]){
                if(stops<=k && dist+nei.second<=distance[nei.first]){
                    q.push({stops+1, {nei.first, dist+nei.second}});
                    distance[nei.first] = dist+nei.second;
                }
            }
        }
        return distance[dst]==INT_MAX?-1:distance[dst];
    }
};

int main(){
    int n, m, src, dst, k;
    cin >> n >> m >> src >> dst >> k;
    
    vector<vector<int>> flights(m, vector<int>(3));
    for(int i = 0; i < m; i++) {
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    }
    
    Solution sol;
    int result = sol.findCheapestPrice(n, flights, src, dst, k);
    cout << result << endl;
    return 0;
}