// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
#include<bits/stdc++.h>
using namespace std;

int longestAPd(vector<int>&nums, int d){
    int n = nums.size();
    unordered_map<int,int>dp;
    int ans = 0;
    for(int i=0;i<n;i++){
        int temp = nums[i] - d;
        int t = 0;
        if(dp.count(temp)){
            t = dp[temp];
        }
        dp[nums[i]] = 1 + t;
        ans = max(ans,dp[nums[i]]);
    }
    return ans;
}