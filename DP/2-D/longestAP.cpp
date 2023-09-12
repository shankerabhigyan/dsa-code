#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int index, int d){
    if(index<0){
        return 0;
    }
    int ans = 0;
    for(int j=index-1;j>=0;j--){
        if(nums[j]-nums[index]==d){
            ans = max(ans,1+solve(nums,j,d));
        }
    }
    return ans;
}

int bruteForce(vector<int>&nums){
    int n = nums.size();
    if(n<=2){
        return nums.size();
    }
    int ans = 0;
    for(int i=0; i<n;i++){
        for(int j=i+1;j<n;j++){
            ans = max(ans,2+solve(nums,i,nums[i]-nums[j]));
        }
    }
    return ans;
}

int solveMem(vector<int>&nums, int index, int d, unordered_map<int,int> dp[]){
    if(index<0){
        return 0;
    }
    if(dp[index].count(d)){
        return dp[index][d];
    }
    int ans = 0;
    for(int j=index-1;j>=0;j--){
        if(nums[j]-nums[index]==d){
            ans = max(ans,1+solveMem(nums,j,d,dp));
        }
    }
    return dp[index][d] = ans;
}

int Memoization(vector<int>&nums){
    int n = nums.size();
    unordered_map<int,int> dp(n+1);
    if(n<=2){
        return nums.size();
    }
    int ans = 0;
    for(int i=0; i<n;i++){
        for(int j=i+1;j<n;j++){
            ans = max(ans,2+solveMem(nums,i,nums[i]-nums[j],dp));
        }
    }
    return ans;
}

int longestAP(vector<int> &nums){
    //return bruteForce(nums); // -- suboptimal brute force solution
    return Memoization(nums);
}

int longestAPTab(vector<int>&nums){
    int n = nums.size();
    if(n<=2){
        return n;
    }
    int ans = 0;
    unordered_map<int,int> dp[n+1];
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            int d = nums[i] - nums[j];
            int count = 1;
            if(dp[j].count(d)){
                count = dp[j][d];
            }
            dp[i][d] = 1+count;
            ans = max(ans,dp[i][d]);
        }
    }
    return ans;
}

// todo : implement space O(n) solution using 2*b = a+c

int main(){
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    cout << longestAP(nums) << endl;
}