// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/
#include<bits/stdc++.h>
using namespace std;

void swap_(vector<int>&nums1, vector<int>&nums2, int idx){
    int temp = nums1[idx];
    nums1[idx] = nums2[idx];
    nums2[idx] = temp;
}

int solve(vector<int> &nums1, vector<int> &nums2, int idx, bool swapped){
    if(idx==nums1.size()){
        return 0;
    }
    
}

int minSwap(vector<int>&nums1, vector<int>&nums2){
    vector<int> numss1(nums1.size()+1);
    vector<int> numss2(nums1.size()+1);
    numss1[0] = -1;
    numss2[0] = -1;
    for(int i=1;i<numss1.size();i++){
        numss1[i] = nums1[i-1];
        numss2[i] = nums2[i-1];
    }
    vector<int>dp(numss1.size(),-1);
    return solve(numss1,numss2,1,dp);
}

int main(){
    int n;
    cin >> n;
    vector<int>nums1(n,0);
    vector<int>nums2(n,0);
    for(int i=0;i<n;i++){
        cin >> nums1[i];
    }
    for(int i=0;i<n;i++){
        cin >> nums2[i];
    }
    cout << minSwap(nums1,nums2) << endl;
    return 0;
}