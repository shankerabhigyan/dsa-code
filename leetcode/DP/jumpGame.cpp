#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums,int i, vector<int>&dp){
    if(i>=nums.size()-1){
        return 1;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    for(int j=1;j<=nums[i];j++){
        if (solve(nums,i+j,dp)){
            dp[i] = 1;
            return 1;
        }
    }
    dp[i] = 0;
    return 0;
}

bool canJump(vector<int>&nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    int ans = solve(nums,0,dp);
    if(ans) return true;
    return false;
}

void printVector(vector<int>&v){
    for (auto x:v){
        cout << x << " ";
    }
    cout << endl;
}

bool canJumpTab(vector<int>&nums){
    vector<int> dp(nums.size(),0);
    dp[nums.size()-1] = 1;
    for(int i=nums.size()-2;i>=0;i--){
        for(int j=1;j<=nums[i];j++){
            if(i+j<nums.size() && dp[i+j]==1){
                dp[i] = 1;
            }
        }
    }
    return dp[0];
}

bool canJumpOpt(vector<int>&nums){
    int maxJump = nums[0];
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0 && maxJump==i){
            return false;
        }
        if(i+nums[i]>maxJump){
            maxJump = i+nums[i];
        }
        if(maxJump>=nums.size()-1){
            return true;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    cout << canJumpTab(nums) << endl;
    return 0;
}