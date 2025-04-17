# https://leetcode.com/problems/permutations-ii/description/?envType=problem-list-v2&envId=backtracking

from typing import List

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        def permute(vec):
            if len(vec)==0:
                return [[]]
            ans = []
            arr = permute(vec[1:])
            for el in arr:
                for i in range(len(el)+1):
                    if i>0 and vec[i-1]==vec[0]:
                        continue
                    elcopy = el.copy()
                    elcopy.insert(i,vec[0])
                    ans.append(elcopy)

            return ans
        return permute(nums)