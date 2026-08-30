from typing import List

class Solution:
    def minCost(self, s: str, cost: List[int]) -> int:
        hmap = {}
        maxVal, total = 0,0
        for i in range(len(s)):
            if s[i] not in hmap:
                hmap[s[i]] = 0
            hmap[s[i]] += cost[i]
            total += cost[i]
            if hmap[s[i]]>maxVal:
                maxVal = hmap[s[i]]
        
        return total-maxVal