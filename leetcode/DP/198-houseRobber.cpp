#include<bits/stdc++.h>
using namespace std;

vector<int> getNewArray(vector<int>nums, int i){
    if(i==0){
        nums.erase(nums.begin());
        nums.erase(nums.begin());
    }
    else if(i==nums.size()-1){
        nums.erase(nums.end()-1);
        nums.erase(nums.end()-1);
    }
    else{
        nums.erase(nums.begin()+i);
        nums.erase(nums.begin()+i); 
        nums.erase(nums.begin()+i-1);
    }
    return nums;
}


int recurse(vector<int>&nums){
    if(nums.size()==0){
        return 0;
    }
    if(nums.size()==1){
        return nums[0];
    }
    if(nums.size()==2){
        return max(nums[0],nums[1]);
    }
    else{
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            vector<int> newNums = getNewArray(nums,i);
            ans = max(ans,nums[i]+recurse(newNums));
        }
        return ans;
    }
}

int rob(vector<int>&nums){
    int ans;
    ans = recurse(nums);
    return ans;
}

int robTab(vector<int>&nums){
    int n = nums.size();
    if(n==1){
        return nums[0];
    }
    vector<int> dp(n+1,0);
    dp[n] = 0;
    dp[n-1] = nums[n-1];
    dp[n-2] = max(nums[n-1],nums[n-2]);
    for(int i=n-2;i>=0;i--){
        dp[i] = max(nums[i]+dp[i+2],dp[i+1]);
    }
    return dp[0];
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout << robTab(nums) << endl;
    return 0;
}