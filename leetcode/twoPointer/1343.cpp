#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int y=0,len=arr.size(),x=0,sum=0,ans=0;
    while(y<k-1){
      sum+=arr[y++];
    }
    while(y<len){
      if(sum+arr[y]>k*threshold) ans++;
      sum = sum - x++ + y++;
    }
    return ans;
  }
};