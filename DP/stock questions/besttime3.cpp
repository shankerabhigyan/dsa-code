// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>&prices){
    int n = prices.size();
    int k = 2;
    vector<vector<int>> dp(k+1,vector<int>(n,0));
    for(int i=1;i<=k;i++){
        int maxDiff = INT_MIN;
        for(int j=1;j<n;j++){
            maxDiff = max(maxDiff,dp[i-1][j-1]-prices[j-1]);
            dp[i][j] = max(dp[i][j-1],maxDiff+prices[j]);
        }
    }
    return dp[k][n-1];
}

int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for(auto p:prices){
        cin >> p;
    }
    cout << maxProfit(prices) << endl;
    return 0;
}