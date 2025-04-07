# https://leetcode.com/problems/combination-sum/

from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        def backtrack(arr, i, sum)->None:
            if sum == target:
                ans.append(arr.copy())
                return
            if i == len(candidates) or sum>target:
                return
        
            # to take
            arr.append(candidates[i])
            backtrack(arr,i,sum+candidates[i])

            # not to take
            arr.pop()
            backtrack(arr, i+1, sum)
            return
        
        backtrack([],0,0)
        return ans