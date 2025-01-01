#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    int binsearch(vector<int>& nums, int target){
        int s=0,e=nums.size()-1;
        while(s<=e){
            int m = s + (e-s)/2;
            if(nums[m]==target) return m;
            if(nums[m]>target) e=e-1;
            else s=s+1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx = binsearch(nums,target);
        if(idx==-1) return {-1,-1};
        vector<int> ans(2,idx);
        while(ans[0]-1>=0 && nums[ans[0]-1]==target) ans[0]--;
        while(ans[1]+1<nums.size() && nums[ans[1]+1]==target) ans[1]++;
        return {ans[0],ans[1]};
    }
};
int main(){
    return 0;
}