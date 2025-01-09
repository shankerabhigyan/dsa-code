#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recurse(vector<int>& coins, vector<vector<int>>& dp, int amount, int i){
        if(amount == 0) return 0;
        if(i == coins.size() || amount < 0) return INT_MAX;
        
        if(dp[i][amount] != -1) return dp[i][amount];
        
        int result = INT_MAX;
        
        // Try using current coin
        int take = recurse(coins, dp, amount - coins[i], i);
        if(take != INT_MAX)
            result = take + 1;
            
        // Try skipping current coin
        int skip = recurse(coins, dp, amount, i + 1);
        if(skip != INT_MAX)
            result = min(result, skip);
        
        return dp[i][amount] = result;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int ans = recurse(coins, dp, amount, 0);
        return ans == INT_MAX ? -1 : ans;
    }
};
int main(){
    return 0;
}