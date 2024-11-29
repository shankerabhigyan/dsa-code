// https://leetcode.com/problems/subsets/description/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void recurse(int i, vector<int>&nums, vector<int>temp, vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        else{
            temp.push_back(nums[i]);
            recurse(i+1,nums,temp,ans);
            temp.pop_back();
            recurse(i+1,nums,temp,ans);
            return;
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        recurse(0,nums,{},ans);
        return ans;
    }
};

// MASKING APPROACH

class Solution{
public:
    vector<vector<int>> subsets(vector<int>& nums){
        int n = nums.size();
        int totalsubs = 1 << n;
        vector<vector<int>> ans;
        ans.reserve(totalsubs);

        for(int mask=0; mask<totalsubs; mask++){
            vector<int>subset;
            subset.reserve(n);

            for(int i=0;i<n; i++){
                if(mask & (1<<i)){
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(move(subset));
        }
        return ans;
    }
};