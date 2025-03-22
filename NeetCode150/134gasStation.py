# https://leetcode.com/problems/gas-station/

# greedy

from typing import List

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas)<sum(cost):
            return -1
        
        ans = 0
        tot = 0
        for i in range(len(gas)):
            tot += gas[i] - cost[i]
            if tot<0:
                tot = 0
                ans = i+1
        
        return ans
