// https://leetcode.com/problems/triangle/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> dp(m,0);
        for(int i=0;i<m;i++){
            dp[i] = triangle[m-1][i];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[j] = min(dp[j],dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};

int main(){
    return 0;
}