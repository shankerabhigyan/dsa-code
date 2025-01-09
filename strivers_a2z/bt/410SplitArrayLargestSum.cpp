#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/split-array-largest-sum/

class Solution {
public:
    bool isPossible(vector<int>&nums, int k, int m, int &n){
        int sum = 0;
        for(int i=0;i<n;i++){
            if(k==0) return false;
            sum+=nums[i];
            if(sum>m){
                sum -= nums[i];
                i--;
                sum = 0;
                k--;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) return -1;
        int s=nums[0],e=0;
        for(int &num:nums){
            s = min(s,num);
            e += num;
        }
        while(s<=e){
            int m = s + (e-s)/2;
            bool ans = isPossible(nums,k,m,n);
            if(ans){
                e = m-1;
            }
            else{
                s = m+1;
            }
        }
        return s;
    }
};

int main(){
    return 0;
}