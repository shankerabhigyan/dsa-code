#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/perfect-squares/

int getnumSquares(int n, vector<int> &dp){
    if(n==0||n==1||n==2||n==3){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans = INT_MAX;
    for(int i=1;i*i<=n;i++){
        ans = min(getnumSquares(n-(i*i),dp),ans);
    }
    return dp[n]=ans+1;
}

int numSquares(int n){
    vector<int> dp(n+1,-1);
    return getnumSquares(n,dp);
}

int getnumSquaresTab(int n){
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=i;j++){
            dp[i] = min(dp[i],dp[i-(j*j)]+1);
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    cout << getnumSquaresTab(n) << endl;
    return 0;
}