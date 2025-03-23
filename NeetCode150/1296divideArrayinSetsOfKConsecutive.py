# https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/description/

from typing import List
import heapq

class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        hashmap = {}
        heap = []

        for num in nums:
            if num not in hashmap:
                hashmap[num] = 0
                heapq.heappush(heap,num)
            hashmap[num] += 1
        
        while len(hashmap)>0:
            min = heap[0]
            for i in range(min,min+k):
                if i in hashmap:
                    hashmap[i] -= 1
                    if hashmap[i]==0:
                        if i!=heap[0]:
                            return False
                        else:
                            hashmap.pop(i)
                            heapq.heappop(heap)
                else:
                    return False
                
        return True