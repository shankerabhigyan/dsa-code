#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/maximal-square/

int getmaximalSquares(vector<vector<char>> &matrix, int i, int j, int &sol, vector<vector<int>>&dp){ // return area (TLE)
    if(i>=matrix.size()||j>=matrix[0].size()){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int a = getmaximalSquares(matrix,i+1,j,sol,dp);
    int b = getmaximalSquares(matrix,i,j+1,sol,dp);
    int c = getmaximalSquares(matrix,i+1,j+1,sol,dp);
    
    if(matrix[i][j]=='1'){
        int d = 1 + min(a,min(b,c));
        sol = max(sol,d*d);
        return d;
    }
    return 0;
}

int maximalSquares(vector<vector<char>> &matrix){
    int sol = 0;
    vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
    getmaximalSquares(matrix,0,0,sol,dp);
    return sol;
}

int getmaximalSquaresTab(vector<vector<char>> &matrix){ // better than 90% LC
    int sol = 0;
    vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
    for(int i=1;i<=matrix.size();i++){
        for(int j=1;j<=matrix[0].size();j++){
            if(matrix[i-1][j-1]=='1'){
                dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                sol = max(sol,dp[i][j]*dp[i][j]);
            }
        }
    }
    return sol;
}