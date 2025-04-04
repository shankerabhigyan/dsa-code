# https://leetcode.com/problems/car-fleet/description/

from typing import List

class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pairs = [(position[i],speed[i]) for i in range(len(speed))]
        fleets = t = 0
        pairs = sorted(pairs,reverse=True)
        for dist,spd in pairs:
            dest_time = (target-dist)/spd
            if t<dest_time:
                fleets+=1
                t = dest_time
            
        return fleets