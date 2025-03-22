# https://leetcode.com/problems/hand-of-straights/

from typing import List
import heapq

class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand)%groupSize!=0:
            return False
        
        hashmap = {}
        heap = []
        for card in hand:
            if card not in hashmap:
                hashmap[card] = 0
                heapq.heappush(heap,card)
            hashmap[card]+=1

        while len(hashmap)>0:
            mini = heapq.heappop(heap)
            for i in range(mini, mini+groupSize):
                if i in hashmap:
                    hashmap[i] -= 1
                    if hashmap[i]==0:
                        if i==heap[0]:
                            heapq.heappop(heap)
                            hashmap.pop(i)
                        else:
                            return False
                        
                else:
                    return False
                
        return True