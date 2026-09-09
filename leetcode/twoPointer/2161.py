# https://leetcode.com/problems/partition-array-according-to-given-pivot/

from typing import List

class Solution:
  def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
    i,j,n=0,len(nums)-1,len(nums)
    ans=[0]*len(nums)
    ii,jj=0,n-1
    while(i<n):
      if(nums[i]<pivot):
        ans[ii]=nums[i]
        ii+=1
      if(nums[j]>pivot):
        ans[jj]=nums[j]
        jj-=1
      i,j=i+1,j-1
    while(ii<=jj):
      ans[ii]=pivot
      ii+=1
    return ans
        
    
    