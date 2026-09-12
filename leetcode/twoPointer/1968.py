# https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/
from typing import List
class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
      for i in range(1, len(nums) - 1):
        if nums[i - 1] > nums[i] > nums[i + 1] or nums[i - 1] < nums[i] < nums[i + 1]:
          nums[i + 1], nums[i] = nums[i], nums[i + 1]
      return nums