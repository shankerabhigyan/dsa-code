// https://leetcode.com/problems/minimum-sideway-jumps/
#include<bits/stdc++.h>
using namespace std;

int getminSideJumpsMem(vector<int>&obstacles, int &n, int x, int y, vector<vector<int>> &dp){
    if(x==n){
        return 0;
    }
    if(dp[x][y]!=-1){
        return dp[x][y];
    }
    if(obstacles[x+1]==y){
        int ans = INT_MAX;
        for(int i=1;i<=3;i++){
            if(i!=y && obstacles[x]!=i){
                continue;
            }
            ans = min(ans,1+getminSideJumpsMem(obstacles,n,x+1,i,dp));
        }
        dp[x][y] = ans;
        return dp[x][y];
    }
    else{
        return dp[x][y] = getminSideJumpsMem(obstacles,n,x+1,y,dp);
    }
}


int minSideJumps(vector<int> &obstacles){
    int n = obstacles.size()-1;
    vector<vector<int>> dp(n,vector<int>(4,-1));
    int ans = getminSideJumpsMem(obstacles,n,0,2,dp);
    return ans;
}

int minSideJumpsTab(vector<int> obstacles){
    int n = obstacles.size()-1;
    vector<vector<int>> dp(n+1,vector<int>(4,INT_MAX));
    for(int i=0;i<=3;i++){
        dp[n][i] = 0;
    }
    for(int x=n-1;x>=0;x--){
        for(int y=1;y<=3;y++){
            if(obstacles[x+1]!=y){
                dp[x][y] = dp[x+1][y];
            }
            else{
                for(int i=1;i<=3;i++){
                    if(i!=obstacles[x+1] && i!=obstacles[x]){
                        dp[x][y] = min(dp[x][y],1+dp[x+1][i]);
                    }
                }
            }
        }
    }
    return min(dp[0][2],min(1+dp[0][1],1+dp[0][3]));
}

int minimumSideJumps(vector<int> &obstacles){
    vector<int> next(4,0);
    for(int x=n-1;x>=0;x--){
        vector<int> curr(4,INT_MAX);
        for(int y=1;y<=3;y++){
            if(obstacles[x+1]!=y){
                curr[y] = next[y];
            }
            else{
                for(int i=1;i<=3;i++){
                    if(i!=obstacles[x+1] && i!=obstacles[x])
                    curr[y] = min(curr[y],1+next[i]);
                }
            }
        }
        next = curr;
    }
    return min(next[2],1+min(next[1],next[3]));
} 

int main(){
    int n;
    cin >> n;
    vector<int> obstacles(n+1,0);
    for(int i=0;i<=n;i++){
        cin >> obstacles[i];
    }
    cout << minSideJumps(obstacles)<<endl;
    return 0;
}