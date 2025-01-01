#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;
        while(s<=e){
            int m = s + (e-s)/2;
            if(nums[m]>=target){
                e = m-1;
            }
            if(nums[m]<target){
                s = m + 1;
            }
        }
        return s;
    }
};

int main(){
    return 0;
}