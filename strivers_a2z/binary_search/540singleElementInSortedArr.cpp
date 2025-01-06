#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int s=0,e=nums.size()-1;
        int m;
        while(s<=e){
            m = s + (e-s)/2;
            if((m>0 && nums[m]!=nums[m-1] && m<nums.size()-1 && nums[m]!=nums[m+1]) || 
            (m==0 && nums[m]!=nums[m+1]) || (m==nums.size()-1 && nums[m]!=nums[m-1])){
                return nums[m];
            }
            if((m-s)&1){
                if(nums[m]==nums[m-1]) s=m+1;
                else e=m-1;
            }
            else{
                if(nums[m]==nums[m-1]) e=m-2;
                else s=m+2;
            }
        }
        return nums[m];
    }
};
int main(){
    return 0;
}