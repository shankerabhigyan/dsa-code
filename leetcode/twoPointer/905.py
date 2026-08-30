# https://leetcode.com/problems/sort-array-by-parity/description/

from typing import List

#inplace solution
# class Solution:
#   def sortArrayByParity(self, nums: List[int]) -> List[int]:
#     i,j = 0,len(nums)-1
#     while(i<j):
#       if(nums[i]%2==1 and nums[j]%2==0):
#        t = nums[i]
#        nums[i] = nums[j]
#        nums[j] = t
#       elif(nums[i]%2==0 and nums[j]%2==1):
#         i+=1
#         j-=1
#       elif(nums[j]%2==0):
#         i+=1
#       else:
#         j-=1
#     return nums
  
  
class Solution:
  def sortArrayByParity(self, nums: List[int]) -> List[int]:
    n = len(nums)
    numsNew,e,o = [0]*n,0,n-1
    for i in range(0,n):
      if(not nums[i]%2):
        numsNew[e] = nums[i]
        e+=1
      else:
        numsNew[o] = nums[i]
        o-=1
    return numsNew
