#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int x=m-1;x>=0;x--){
            dp[x][n-1]=1;
        }
        for(int x = m-1;x>=0;x--){
            for(int y=n-2;y>=0;y--){
                dp[x][y] += dp[x][y+1];
                if(x+1<m) dp[x][y] += dp[x+1][y];
            }
        }
        return dp[0][0];
    }
};

int main(){
    return 0;
}