// https://leetcode.com/problems/min-cost-climbing-stairs/
// 746. Min Cost Climbing Stairs
#include<bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int> &cost){
    int n = cost.size();
    //vector<int> mincost(n);
    int s1 = cost[0];
    int s2 = cost[1];
    for(int i=2;i<n;i++){
        int curr = min(s1,s2) + cost[i];
        s1 = s2;
        s2 = curr;
    }
    return min(s1,s2);
}

int main(){
    vector<int> cost;
    int x;
    cin >> x;
    while(x!=-1){
        cost.push_back(x);
        cin >> x;
    }

    cout << minCostClimbingStairs(cost) << endl;
    
    return 0;
}