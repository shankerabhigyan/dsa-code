#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0, e=nums.size()-1;
        while(s<=e){
            int m = s + (e-s)/2;
            if(nums[m]==target) return m;
            else if(nums[s]<=nums[m]){ // first half sorted
                if(target>=nums[s] && target<nums[m]){ // can be in the first half
                    e = m-1;
                }
                else{
                    s = m+1;
                }
            }
            else{ // second half sorted
                if(target>nums[m] && target<=nums[e]){
                    s = m+1;
                }
                else{
                    e = m-1;
                }
            }
        }      
        return -1;
    }
};

int main(){
    return 0;
}