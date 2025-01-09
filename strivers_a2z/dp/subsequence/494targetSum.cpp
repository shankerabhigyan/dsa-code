#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/target-sum/


class Solution {
public:
    int recurse(vector<int>& nums, int target, int i, unordered_map<int,unordered_map<int,int>>&dp){
        if(i==nums.size()){
            if(target==0) return 1;
            return 0;
        }
        if(dp[i][target])return dp[i][target];
        return dp[i][target]=recurse(nums,target-nums[i],i+1,dp) + recurse(nums,target+nums[i],i+1,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,unordered_map<int,int>> dp;
        return recurse(nums,target,0,dp);
    }
};

int main(){
    return 0;
}