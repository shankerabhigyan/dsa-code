#include<bits/stdc++.h>
using namespace std;

int traceGraph(int x, int y, vector<vector<int>>&grid, vector<vector<int>> &dp, int &n, int &m){
    if(x==m-1 && y==n-1){
        return 1;
    }
    if(dp[x][y]!=-1) return dp[x][y];
    dp[x][y] = 0;
    if(x<m-1 && grid[x+1][y]!=1) dp[x][y] += traceGraph(x+1,y,grid,dp,n,m);
    if(y<n-1 && grid[x][y+1]!=1) dp[x][y] += traceGraph(x,y+1,grid,dp,n,m);
    return dp[x][y];
}

int uniquePaths(vector<vector<int>>&grid){
    int n = grid[0].size();
    int m = grid.size();
    if(grid[m-1][n-1]==1 || grid[0][0]==1) return 0;
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return traceGraph(0,0,grid,dp,n,m);
}

int main(){
    // int m, n;
    // cin >> m >> n;
    // vector<vector<int>>grid(n,vector<int>(m,0));
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cin >> grid[i][j];
    //     }
    // }
    vector<vector<int>> grid = {{0,0}};
    cout << uniquePaths(grid) << endl;
    return 0;
}