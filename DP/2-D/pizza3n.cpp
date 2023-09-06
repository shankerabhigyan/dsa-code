// https://leetcode.com/problems/pizza-with-3n-slices/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&slices,int k, int i, int &n){
    if(k==0 || i>n){
        return 0;
    }
    int inc = slices[i] + solve(slices,k-1,i+2,n);
    int exc = solve(slices,k,i+1,n);

    return max(inc,exc);
}

int solveMem(vector<int>&slices,int k, int i, int n, vector<vector<int>> &dp){
    if(k==0 || i>n){
        return 0;
    }
    if(dp[i][k]!=-1){
        return dp[i][k];
    }
    int inc = slices[i] + solveMem(slices,k-1,i+2,n,dp);
    int exc = solveMem(slices,k,i+1,n,dp);

    return dp[i][k] = max(inc,exc);
}

int maxSizeSlices(vector<int>&slices){
    int n = slices.size();
    vector<vector<int>> dp1(n,vector<int>(n,-1));
    vector<vector<int>> dp2(n,vector<int>(n,-1));
    return max(solveMem(slices,n/3,0,n-2,dp1),solveMem(slices,n/3,1,n-1,dp2));
}

int main(){
    int n;
    cin >> n;
    vector<int> slices(3*n);
    for(int i=0;i<3*n;i++){
        cin >> slices[i];
    }
    cout << maxSizeSlices(slices) << endl;
    return 0;
}
