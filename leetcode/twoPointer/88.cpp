#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/merge-sorted-array/description/


class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int x=0,y=0;
    vector<int> ans(m+n);
    while(x<m && y<n){
      ans[x+y-1] = nums1[x]<nums2[y]?nums1[x++]:nums2[y++];
    }
    while(x<m){
      ans[x+y-1] = nums1[x++];
    } 
    while(y<n){
      ans[x+y-1] = nums2[y++];
    }
    nums1=ans;
  }
};