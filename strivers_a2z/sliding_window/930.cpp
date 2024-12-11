// https://leetcode.com/problems/binary-subarrays-with-sum/description/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int numSubarraysWithSum(vector<int>&nums, int goal){
        int l=0,r=0,sum=0;
        int n = nums.size();
        int ans = 0;
        while(r<n){
            sum+=nums[r];
            if(sum>goal){

            }
            else{
                
            }
            r++
        }
    }
};

int main(){

    return 0;
}