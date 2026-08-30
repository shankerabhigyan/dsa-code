from typing import List

class Solution:
  def sortedSquares(self, nums: List[int]) -> List[int]:
    a,b,i = 0,len(nums)-1,len(nums)-1
    arr = [0]*len(nums)
    while(a<=b):
      if(abs(nums[a])>abs(nums[b])):
        arr[i] = nums[a]**2
        a+=1
        i-=1
      else:
        arr[i] = nums[b]**2
        i-=1
        b-=1
    return arr
      