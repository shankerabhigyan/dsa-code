# https://leetcode.com/problems/contains-duplicate/

import collections

class Solution(object):
    def containsDuplicate(self, nums):
        map = collections.defaultdict(int) # hash table
        for num in nums:
            if num in map:
                return True
            map[num] = 1
        return False
        
        