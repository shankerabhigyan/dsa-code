// https://leetcode.com/problems/unique-paths/description/
#include<bits/stdc++.h>
using namespace std;

int traceGraph(int x, int y, int &m, int &n, vector<vector<int>> &dp){
    if(x==n-1 && y==m-1){
        return 1;
    }
    if(x>=n|| y>=m) return 0;
    if (dp[x][y] != 0) return dp[x][y];
    if(x<n-1) dp[x][y] += traceGraph(x+1,y,m,n,dp);
    if(y<m-1) dp[x][y] += traceGraph(x,y+1,m,n,dp);
    return dp[x][y];
}

int uniquePaths(int m, int n){
    int count = 0;
    vector<vector<int>> dp(n,vector<int>(m,0));
    return traceGraph(0,0,m,n,dp);
}

int main(){
    int m,n;
    cin >> m >> n;
    cout << uniquePaths(m, n) << endl;
    return 0;
}