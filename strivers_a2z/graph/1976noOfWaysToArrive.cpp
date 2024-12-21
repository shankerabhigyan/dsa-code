// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long>cost(n,LONG_MAX);
        vector<int>ways(n,0);
        vector<vector<pair<int,int>>> adj(n); // {node,time}
        for(auto road:roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }
        priority_queue<pair<long,long>, vector<pair<long,long>>, greater<pair<long,long>>>pq;
        pq.push({0,0});
        ways[0] = 1;
        while(!pq.empty()){
            auto [time,node] = pq.top();
            pq.pop();
            if(time>cost[node]) continue;
            for(auto [next,moreTime]:adj[node]){
                if(time+moreTime==cost[next]){
                    ways[next]+=ways[node];
                    ways[next] = ways[next]%MOD;
                }
                if(time+moreTime<cost[next]){
                    ways[next]=ways[node];
                    cost[next] = time+moreTime;
                    pq.push({cost[next],next});
                }
            }
        }
        return ways[n-1];
    }
};

int main(){
    return 0;
}