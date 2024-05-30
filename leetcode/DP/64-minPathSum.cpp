#include<bits/stdc++.h>
using namespace std;

int recurse(vector<vector<int>>&grid, int &r, int &c, int i, int j, vector<vector<int>> &dp){
    if(i==r-1 && j==c-1){
        return grid[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    else if(i==r-1){
        int sum = 0;
        while(j<=c-1){
            sum+=grid[i][j];
            j++;
        }
        j = c-1;
        return dp[i][j] = sum;
    }
    else if(j==c-1){
        int sum = 0;
        while(i<=r-1){
            sum+=grid[i][j];
            i++;
        }
        i = r-1;
        return dp[i][j] = sum;
    }
    else{
        int ans = 0;
        int temp1 = 0, temp2 = 0;
        // right
        if(j+1<=c-1){
            temp1 = grid[i][j] + recurse(grid, r,c, i, j+1, dp);
        }
        // down
        if(i+1<=r-1){
            temp2 = grid[i][j] + recurse(grid, r,c, i+1, j, dp);
        }
        ans = min(temp1,temp2);
        dp[i][j] = ans;
        return ans;
    }
}

int minPathSum(vector<vector<int>>&grid){
    int c = grid[0].size();
    int r = grid.size();
    vector<vector<int>> dp(r, vector<int>(c,-1));
    int ans = recurse(grid,r,c,0,0,dp);
    return ans;
}

int main(){
    int r,c;
    cin >> r >> c;
    vector<vector<int>> grid(r,vector<int>(c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> grid[i][j];
        }
    }
    cout << minPathSum(grid) << endl;
    return 0;
}