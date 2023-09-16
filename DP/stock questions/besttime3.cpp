// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
#include<bits/stdc++.h>
using namespace std;

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

int maxProfit(vector<int>&prices){
    vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(3,vector<int>(2,-1)));
    return solve(prices,0,2,false,dp);
}

int maxProfitTab(vector<int>&prices){
    int n = prices.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(2,0)));
    for(int i=0;i<n;i++){
        for(int j=1;j<=2;j++){
            if(i==0){
                dp[i][j][0] = 0;
                dp[i][j][1] = -prices[i];
            }
            else{
                dp[i][j][0] = max(dp[i-1][j][0],dp[i-1][j][1]+prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1],dp[i-1][j-1][0]-prices[i]);
            }
        }
    }
    return dp[n-1][2][0];
}

int maxProfitOpt(vector<int>&prices){
    int n = prices.size();
    vector<vector<int>> dp(3,vector<int>(2,0));
    for(int i=0;i<n;i++){
        for(int j=1;j<=2;j++){
            vector<vector<int>> temp(3,vector<int>(2,0));
            if(i==0){
                temp[j][0] = 0;
                temp[j][1] = -prices[i];
            }
            else{
                temp[j][0] = max(dp[j][0],dp[j][1]+prices[i]);
                temp[j][1] = max(dp[j][1],dp[j-1][0]-prices[i]);
            }
        }
        dp = temp;
    }
    return dp[2][0];
}

// implement more optimised solution

int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i=0;i<n;i++){
        cin >> prices[i];
    }
    cout << maxProfit(prices) << endl;
    return 0;
}