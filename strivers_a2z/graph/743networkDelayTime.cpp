#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // -1 if all nodes can't be visited..
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto time:times){
            adj[time[0]].push_back({time[1],time[2]});
        }
        vector<int> cost(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto [dist,node] = pq.top();
            pq.pop();
            if(dist>cost[node]) continue;
            cost[node] = dist;
            for(auto ngb:adj[node]){
                auto [next,wt] = ngb;
                if(dist+wt<cost[next]){
                    cost[next] = dist+wt;
                    pq.push({dist+wt,next});
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans=max(ans,cost[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};

int main(){

    return 0;
}