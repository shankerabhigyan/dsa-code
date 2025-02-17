# https://leetcode.com/problems/longest-consecutive-sequence/description/

import collections

class Solution(object):
    
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        num_set = set(nums)
        ans = 0
        for num in num_set:
            if num-1 not in num_set:
                current_num = num
                current_len = 1
                while current_num+1 in num_set:
                    current_num += 1
                    current_len += 1
                ans = max(ans, current_len)

        return ans
