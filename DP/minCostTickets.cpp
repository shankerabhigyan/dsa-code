#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-cost-for-tickets/

int solve(vector<int> &days, vector<int> &costs, int index){ // recursive solution
    if(index>days.size()-1){
        return 0;
    }

    int a = cost[0] + solve(days,costs,index+1);
    int i=0;

    for(i=index; i<days.size() && days[i]<days[index]+7;i++);
    int b = cost[1] + solve(days,costs,i);

    for(i=index; i<days.size() && days[i]<days[index]+30;i++);
    int c = cost[2] + solve(days,costs,i);

    return min(a,b,c);
}

int solveMem(vector<int> &days, vector<int> &costs, int index, int &n, vector<int> &dp){
    if(index>=n){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }

    int a = costs[0] + solveMem(days,costs,index+1,n,dp);
    int i;
    for(i=index;i<n&&days[i]<days[index]+7;i++);
    int b = costs[1] + solveMem(days,costs,i,n,dp);
    for(i=index;i<n&&days[i]<days[index]+30;i++);
    int c = costs[2] + solveMem(days,costs,i,n,dp);
    return dp[index] = min(a,min(b,c));
}

int solveTab(vector<int> &days, vector<int> &costs){
    int n = days.size();
    vector<int> dp(n+1,INT_MAX);
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
        int a = costs[0] + dp[i+1];
        int k;
        for(k=i;k<n&&days[k]<days[i]+7;k++);
        int b = costs[1] + dp[k];
        for(k=i;k<n&&days[k]<days[i]+30;k++);
        int c = costs[2] + dp[k];
        dp[k] = min(a,min(b,c));
    }
    return dp[0];
}

int mincost(vector<int> &days, vector<int> &costs){
    //return solve(days,costs,0);
    vector<int> dp(days.size(),-1);
    return solveMem(days,costs,0,days.size(),dp);
}

int main(){
    vector<int> days;
    vector<int> costs;
    cout << "Enter days : ";
    int x;
    cin >> x;
    while(x!=-1){
        days.push_back(x);
        cin >> x;
    }
    cout << "Enter costs : ";
    cin >> x;
    while(x!=-1){
        costs.push_back(x);
        cin >> x;
    }
    return 0;
}