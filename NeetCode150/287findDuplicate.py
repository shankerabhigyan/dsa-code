# https://leetcode.com/problems/find-the-duplicate-number/

class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for num in nums:
            if nums[abs(num)-1]<0:
                return abs(num)
            nums[abs(num)-1] *= -1
        return None