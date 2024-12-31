#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

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
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(arr,dp,n-1,target);
    }
};

int main(){
    return 0;
}