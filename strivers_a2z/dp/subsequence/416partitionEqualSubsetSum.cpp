#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool f(vector<int>& arr, vector<vector<int>> &dp, int i, int target){
        if(target==0) return true;
        if(target<0) return false;
        if(i==0) return target==arr[i]?true:false;
        if(dp[i][target]!=-1) return dp[i][target];

        dp[i][target] = f(arr,dp,i-1,target-arr[i]) || f(arr,dp,i-1,target);
        return dp[i][target];
        
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum&1) return false; // odd sum
        int target = sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(nums,dp,n-1,target);
    }
};

int main(){

    return 0;
}