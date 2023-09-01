// https://leetcode.com/problems/longest-increasing-subsequence/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, pair<int,int> p, int index){ // TLE
    if(index==nums.size()){
        return p.second;
    }

    // include
    int include = -1;
    if(nums[index]>p.first){
        include = solve(nums,{nums[index],p.second+1},index+1);
    }
    if(nums[index]<=p.first){
        include = solve(nums,{nums[index],1},index+1);
    }

    // exclude
    int exclude = solve(nums,p,index+1);

    return max(include,exclude);
}

int solveMem(vector<int> &nums, int prev, int curr, vector<vector<int>> &dp){
    if(curr==nums.size()){
        return 0;
    }
    if(dp[prev+1][curr]!=-1){
        return dp[prev+1][curr];
    }
    int include = 0;
    if(prev==-1 || nums[curr]>nums[prev]){
        include = 1 + solveMem(nums,curr,curr+1,dp);
    }
    int exclude = solveMem(nums,prev,curr+1,dp);
    return dp[prev+1][curr] = max(include,exclude);
}

int getLengthLIS(vector<int> &nums){
    vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
    return solveMem(nums,-1,0,dp);
}

int getLengthLISTab(vector<int> &nums){
    int n = nums.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i = n-1;i>=0;i--){
        for(int j=i-1;j>=-1;j--){
            int include = 0;
            if(j==-1 || nums[i]>nums[j]){
                include = 1 + dp[i+1][i+1];
            }
            int exclude = dp[j+1][i+1];
            dp[j+1][i] = max(include,exclude);
        }
    }
    return dp[0][0];
}

int getLengthLISOpt(vector<int> nums){
    int n = nums.size();
    vector<int> dp(n+1,0);
    for(int i=n-1;i>=0;i--){
        int include = 0;
        for(int j=i+1;j<n;j++){
            if(nums[j]>nums[i]){
                include = max(include,dp[j]);
            }
        }
        dp[i] = 1 + include;
    }
    return *max_element(dp.begin(),dp.end());
}

// DP with Binary search
int solveOptimal(vector<int>&nums){
    vector<int> dp;
    for(int i=0;i<nums.size();i++){
        auto it = lower_bound(dp.begin(),dp.end(),nums[i]); //  returns iterator to first element >= nums[i] {O(logn)}
        if(it==dp.end()){
            dp.push_back(nums[i]);
        }
        else{
            *it = nums[i];
        }
    }
    return dp.size();   
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    cout << solveOptimal(nums) << endl;

    return 0;
}