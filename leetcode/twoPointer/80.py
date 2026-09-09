# https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

from typing import List

class Solution:
  def removeDuplicates(self, nums: List[int]) -> int:
    l,r,n=0,0,len(nums)
    while(r<n):
      if(l<2 or nums[r]!=nums[l-2]):
        nums[l]=nums[r]
        l+=1
      r+=1
    return l