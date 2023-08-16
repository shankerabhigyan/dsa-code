#include<bits/stdc++.h>
using namespace std;

int solveMem(vector<int> &nums, int i, vector<int> &dp){ // solve using Memoization 
    if(i>nums.size()-1){
        return 0;
    }
    if(dp[i]!=INT_MIN){
        return dp[i];
    }
    int m1 = nums[i]+solve(nums,i+2,dp);
    int m2 = solve(nums,i+1,dp);
    dp[i] = max(m1,m2);
    return dp[i];
}

int maximumNonAdjSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,INT_MIN);
    int sum = solveMem(nums,0,dp);
    return sum;
}

int maximumNonAdjSumTab(vector<int> &nums){
    int n = nums.size();
    if(n==0){
        return 0;
    }
    if(n==1){
        return nums[0];
    }
    //vector<int> dp(n,INT_MIN);
    int m2 = nums[n-1];
    int m1 = max(nums[n-1],nums[n-2]);
    int curr;
    for(int i=n-3;i>=0;i--){
        curr = max(nums[i]+m2,m1);
        m2 = m1;
        m1 = curr;
    }
    return m1;
}

int main(){
    int x;
    vector<int> v;
    cin >> x;
    while(x!=-1){
        v.push_back(x);
        cin >> x;
    }
    cout << maximumNonAdjSum(v) << endl;
    return 0;
}