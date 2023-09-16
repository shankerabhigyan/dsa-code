#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-common-subsequence/

int solve(string &text1, string &text2, int i, int j, vector<vector<int>>&dp){
    if(i==text1.length() || j==text2.length()){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(text1[i]==text2[j]){
        return dp[i][j] = 1 + solve(text1,text2,i+1,j+1,dp);
    }
    else{
        return dp[i][j] = max(solve(text1,text2,i+1,j,dp),solve(text1,text2,i,j+1,dp));
    }
}

int longestCommonSubsequence(string text1, string text2){
    vector<vector<int>> dp(text1.length(),vector<int>(text2.length(),-1));
    return solve(text1,text2,0,0,dp);
}

int longestCommonSubsequenceTab(string text1, string text2){
    int n = text1.length();
    int m = text2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}

int longestCommonSubsequenceOpt(string text1, string text2){
    int n = text1.length();
    int m = text2.length();
    vector<int> dp(m+1,0);
    for(int i=1;i<=n;i++){
        int prev = 0;
        for(int j=1;j<=m;j++){
            int temp = dp[j];
            if(text1[i-1]==text2[j-1]){
                dp[j] = 1 + prev;
            }
            else{
                dp[j] = max(dp[j],dp[j-1]);
            }
            prev = temp;
        }
    }
    return dp[m];
}

int main(){
    string text1,text2;
    cin >> text1 >> text2;
    cout << longestCommonSubsequence(text1,text2) <<  endl;
    return 0;
}