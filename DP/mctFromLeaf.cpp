#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

int getMax(vector<int>&arr,int i, int j){
    int ans = INT_MIN;
    while(i<=j){
        ans = max(ans,arr[i]);
        i++;
    }
    return ans;
}

int solveNonLeaf(vector<int>&arr, int i, int j, vector<vector<int>>&dp, map<pair<int,int>,int> &mp){
    if(j==i){
        return 0;
    }
    if(j==i+1){
        return arr[i]*arr[j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = INT_MAX;
    for(int k=i+1;k<=j;k++){
        ans = min(ans, mp[{i,k-1}]*mp[{k,j}] + solveNonLeaf(arr,i,k-1,dp,mp) + solveNonLeaf(arr,k,j,dp,mp));
    }
    return dp[i][j] = ans;
}

int mct(vector<int>&arr){
    vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),-1));
    map<pair<int,int>,int> mp;
    for(int i=0;i<arr.size();i++){
        mp[{i,i}] = arr[i];
        for(int j=i+1;j<arr.size();j++){
            mp[{i,j}] = max(mp[{i,j-1}],arr[j]);
        }
    }
    return solveNonLeaf(arr,0,arr.size()-1,dp,mp);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << mct(arr) << endl;
}