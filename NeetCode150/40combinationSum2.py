# https://leetcode.com/problems/combination-sum-ii/

from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        candidates.sort()
        def dfs(arr,i,sum):
            if sum==target:
                ans.append(arr.copy())
                return
            if sum>target or i==len(candidates):
                return

            arr.append(candidates[i])
            dfs(arr,i+1,sum+candidates[i])
            arr.pop()
            ####
            while i+1 < len(candidates) and candidates[i]==candidates[i+1]:
                i+=1
            dfs(arr,i+1,sum)
        
        dfs([],0,0)
        return ans