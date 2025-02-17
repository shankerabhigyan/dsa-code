# https://leetcode.com/problems/top-k-frequent-elements/description/

import collections

class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        hash_map = collections.defaultdict(int)
        for num in nums:
            hash_map[num] += 1
        bucket = [[] for _ in range(len(nums)+1)]
        # here bucket is a list of lists
        # index = the count of how many times the element(s) at that index occur
        for key in hash_map:
            bucket[hash_map[key]].append(key)
        res = []
        for i in range(len(nums),0,-1): # iterate from the end
            if bucket[i]:
                res += bucket[i]
            if len(res)>=k:
                break

        return res[:k]
        