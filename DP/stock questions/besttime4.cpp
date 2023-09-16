#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

int solve(vector<int>&prices, int i, int lim, bool holding, vector<vector<vector<int>>>&dp){
    if(i==prices.size() || lim==0){
        return 0;
    }
    int ans=0;
    if(dp[i][lim][holding]!=-1){
        return dp[i][lim][holding];
    }
    if(holding){
        int sell = prices[i] + solve(prices,i+1,lim-1,false,dp);
        int notSell = solve(prices,i+1,lim,true,dp);
        ans = max(sell,notSell);
        return dp[i][lim][holding] = ans;
    }
    if(!holding){
        int buy = -prices[i] + solve(prices,i+1,lim,true,dp);
        int notBuy = solve(prices,i+1,lim,false,dp);
        ans = max(buy,notBuy);
        return dp[i][lim][holding] = ans;
    }
    return ans;
}

int maxProfit(int k,vector<int>&prices){
    vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(3,vector<int>(2,-1)));
    return solve(prices,0,,false,dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i=0;i<n;i++){
        cin >> prices[i];
    }
    int k;
    cin >> k;
    cout << maxProfit(k,prices) << endl;
    return 0;
}