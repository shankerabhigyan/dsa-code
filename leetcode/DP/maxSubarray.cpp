#include<bits/stdc++.h>
using namespace std;

int getMaxSubarray(vector<int>&nums, int i, bool empty, vector<vector<int>> &dp){
    if(i==nums.size()){
        if(empty){
            return INT_MIN;
        }
        return 0;
    }

    if(empty){
        if(dp[i][0]!=INT_MIN) return dp[i][0];
        return dp[i][0]  = max(getMaxSubarray(nums,i+1,true,dp), nums[i]+getMaxSubarray(nums,i+1,false,dp));
    }
    if(dp[i][1]!=INT_MIN) return dp[i][1];
    return dp[i][1] = max(0,nums[i]+getMaxSubarray(nums,i+1,false,dp));
}

int maxSubArray(vector<int>&nums){
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(2,INT_MIN));
    return getMaxSubarray(nums, 0, true, dp);
}

int maxSubArrayTab(vector<int>&nums){
    int n = nums.size();
    vector<vector<int>> dp(n+1,vector<int>(2,INT_MIN));
    dp[n][0] = INT_MIN;
    dp[n][1] = 0;
    for(int i=n-1;i>=0;i--){
        dp[i][0] = max(dp[i+1][0],nums[i]+dp[i+1][1]);
        dp[i][1] = max(0,dp[i+1][1]+nums[i]);
    }
    return dp[0][0];
}

int maxSubArrayTabOpt(vector<int>&nums){
    int n = nums.size();
    int p1 = INT_MIN;
    int p2 = 0;
    for(int i=n-1;i>=0;i--){
        int t1 = max(p1,nums[i]+p2);
        int t2 = max(0,nums[i]+p2);
        p1 = t1;
        p2 = t2;
    }
    return p1;
}

int getMaxSubarrayDivideAndConquer(vector<int>&nums, int s, int e, vector<int>&pre, vector<int>&suf){
    if(s==e){
        return nums[s];
    }
    int m = (s+e)/2;
    int left = getMaxSubarrayDivideAndConquer(nums,s,m,pre,suf);
    int right = getMaxSubarrayDivideAndConquer(nums,m+1,e,pre,suf);
    int cross = pre[m]+suf[m+1];
    return max(max(left,right),cross);
}

int maxSubArrayDivideAndConquer(vector<int>&nums){
    int n = nums.size();
    vector<int> pre = nums;
    for(int i=1;i<n;i++){
        pre[i] += max(pre[i-1],0);
    }
    vector<int> suf = nums;
    for(int i=n-2;i>=0;i--){
        suf[i] += max(suf[i+1],0);
    }
    return getMaxSubarrayDivideAndConquer(nums,0,n-1,pre,suf);
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    cout << maxSubArrayDivideAndConquer(nums) << endl;
    return 0;
}