from typing import List

from typing import List

class Solution:
  def removeDuplicates(self, nums: List[int]) -> int:
    w,i,n=0,0,len(nums)
    while(i<n):
      x = nums[i]
      while(i<n and nums[i]==x):
        i+=1
      nums[w]=nums[i-1]
      w+=1
    
    return w