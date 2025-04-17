# https://leetcode.com/problems/permutations-ii/description/?envType=problem-list-v2&envId=backtracking

from typing import List

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        hashmap = {c:0 for c in nums}
        for num in nums:
            hashmap[num] += 1
        res=[]
        perm=[]
        def dfs():
            if len(perm) == len(nums):
                res.append(perm.copy())
            for n in hashmap:
                if hashmap[n] > 0: # add to the current permutation
                    perm.append(n)
                    hashmap[n] -= 1
                    dfs()
                    hashmap[n] += 1
                    perm.pop()
        
        dfs()
        return res
