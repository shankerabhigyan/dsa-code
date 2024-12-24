#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/unique-paths-ii/description/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]) return 0;
        vector<vector<long long>> dp(m+1,vector<long long>(n+1,0));
        dp[m-1][n-1]=1;
        for(int x = m-1;x>=0;x--){
            for(int y=n-1;y>=0;y--){
                if(obstacleGrid[x][y]){
                    dp[x][y]=0;
                    continue;
                }
                dp[x][y] += dp[x][y+1];
                dp[x][y] += dp[x+1][y];
            }
        }
        return dp[0][0];
    }
};

int main(){
    return 0;
}