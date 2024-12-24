#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int x=m-1;x>=0;x--){
            for(int y=n-1;y>=0;y--){
                if(x+1==m) dp[x][y] = dp[x][y+1] + grid[x][y];
                else if(y+1==n) dp[x][y] = dp[x+1][y] + grid[x][y];
                else dp[x][y] = min(dp[x+1][y],dp[x][y+1]) + grid[x][y];
            }
        }
        return dp[0][0];
    }
};

// space optimized solution

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> dp(n);
    
    dp[n-1] = grid[m-1][n-1];
    for(int j = n-2; j >= 0; j--) {
        dp[j] = dp[j+1] + grid[m-1][j];
    }
    
    for(int i = m-2; i >= 0; i--) {
        dp[n-1] += grid[i][n-1];
        for(int j = n-2; j >= 0; j--) {
            dp[j] = min(dp[j], dp[j+1]) + grid[i][j];
        }
    }
    
    return dp[0];
}

int main(){
    return 0;
}