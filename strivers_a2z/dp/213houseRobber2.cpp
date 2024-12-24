#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        if(n==3) return max(nums[0],max(nums[1],nums[2]));
        vector<int> dp(n);
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-1],nums[n-2]);
        for(int i=n-3;i>=1;i--){
            dp[i] = max(dp[i+1],nums[i]+dp[i+2]);
        }

        vector<int> dp1(n);
        dp1[n-2] = nums[n-2];
        dp1[n-3] = max(nums[n-2],nums[n-3]);
        for(int i=n-4;i>=0;i--){
            dp1[i] = max(dp1[i+1],nums[i]+dp1[i+2]);
        }
        return max(dp[1],dp1[0]);
    }
};


int main(){
    return 0;
}