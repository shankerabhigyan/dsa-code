# https://leetcode.com/problems/jump-game/description/

class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        tgt = len(nums)-1
        if tgt==0:
            return True
        for i in range(len(nums)-2, -1, -1):
            if i+nums[i] >= tgt:
                tgt = i
        if tgt==0:
            return True
        return False