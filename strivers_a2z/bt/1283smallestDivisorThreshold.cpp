#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

class Solution {
public:
    bool isPossible(vector<int>& nums, int threshold, int m){
        long ans=0;
        for(int &num:nums){
            ans += (num+m-1)/m;
        }
        return ans<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1,e=threshold;
        while(s<=e){
            int m = s + (e-s)/2;
            bool res = isPossible(nums,threshold,m);
            if(res) e=m-1;
            else s=s+1;
        }
        return s;

    }
};

int main(){
    return 0;
}