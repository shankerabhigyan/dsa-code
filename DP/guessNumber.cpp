// https://leetcode.com/problems/guess-number-higher-or-lower-ii/
#include<bits/stdc++.h>
using namespace std;

int solve(int s, int e, vector<vector<int>> &dp){
    if(s>=e){
        return 0;
    }
    if(dp[s][e]!=-1){
        return dp[s][e];
    }
    int ans = INT_MAX;
    for(int i=s;i<=e;i++){
        int temp = i+max(solve(s,i-1,dp),solve(i+1,e,dp));
        ans = min(ans,temp);
    }
    return dp[s][e] = ans;
}

int getMoneyAmount(int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(1,n,dp);
}


int getMoneyAmountTab(int n){
    vector<vector<int>> dp(n+2,vector<int>(n+1,0));
    for(int s=n;s>=1;s--){
        for(int e=s+1;e<=n;e++){
            int ans = INT_MAX;
            for(int i=s;i<=e;i++){
                int temp = i+ max(dp[s][i-1],dp[i+1][e]);
                ans = min(ans,temp);
            }
            dp[s][e] = ans;
        }
    }
    return dp[1][n];
}

int main(){
    int n;
    cin >> n;
    cout << getMoneyAmount(n) << endl;
    return 0;
}