#include<bits/stdc++.h>
using namespace std;

int getOptJumps(vector<int>&nums, vector<int>&dp, int &n, int i){
    if(i==n-1){
        dp[i] = 0;
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    if(nums[i]==0){
        dp[i] = INT_MAX-nums.size();
        return dp[i];
    }
    int minJumps = INT_MAX;
    for(int j=1; j<=nums[i] && j+i<=n-1 ;j++){
        minJumps = min(minJumps,1+getOptJumps(nums,dp,n,i+j));
    }
    dp[i] = minJumps;
    return minJumps;
}

void printVector(vector<int>&v){
    for (auto x:v){
        cout << x << " ";
    }
    cout << endl;
}

int jump(vector<int>&nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    for(int t=n-1;t>=0;t--){
        getOptJumps(nums,dp,n,t);
    }
    // printVector(dp);
    return dp[0];
}

int jumpTabulation(vector<int>&nums){
    int n = nums.size();
    if(n==1 || n==2){
        return n-1;
    }
    vector<int> dp(n,-1);
    dp[n-1] = 0;
    if(nums[n-2]==0){
        dp[n-2] = INT_MAX - n;
    }
    else{
        dp[n-2] = 1;
    }
    for(int i=n-3; i>=0; i--){
        if(nums[i]==0){
            dp[i] = INT_MAX - n;
            continue;
        }
        int count = INT_MAX;
        for(int j=1;j<=nums[i]&&i+j<=n-1;j++){
            count = min(count, 1+dp[i+j]);
        }
        dp[i] = count;
    }
    //printVector(dp);
    return dp[0];
}

int smartJump(vector<int> &nums){
    for(int i=1;i<=nums.size()-1;i++){
        nums[i] = max(nums[i]+i,nums[i-1]);
    }
    printVector(nums);
    int i=0;
    int ans=0;
    while(i<nums.size()-1){
        ans++;
        i=nums[i];
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    cout << smartJump(nums) << endl;
    return 0;
}