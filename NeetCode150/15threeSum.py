# https://leetcode.com/problems/3sum/description/

import collections

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums = sorted(nums)
        hash_map = collections.defaultdict(int)
        for num in nums:
            hash_map[num] += 1
        ans = []
        for i in range(len(nums)):
            hash_map[nums[i]] -= 1
            if i and nums[i]==nums[i-1]:
                continue
            for j in range(i+1,len(nums)):
                hash_map[nums[j]]-=1
                if j>i+1 and nums[j]==nums[j-1]:
                    continue
                tgt = -nums[i]-nums[j]
                if hash_map[tgt]>0:
                    ans.append((nums[i],nums[j],tgt))

            for j in range(i+1,len(nums)):
                hash_map[nums[j]]+=1
        return ans