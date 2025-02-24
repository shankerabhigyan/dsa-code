# https://leetcode.com/problems/koko-eating-bananas/
# BINARY SEARCH

import math

class Solution(object):
    def isPossible(self, piles, h, m):
        hr = 0
        for pile in piles:
            hr += (pile+(pile%m))//m
            if hr>h:
                return False
        return True
    
    def minEatingSpeed(self, piles, h):
        """
        :type piles: List[int]
        :type h: int
        :rtype: int
        """
        maxi = max(piles)
        s,e = 1,maxi

        while s<=e:
            mid = (e-s)/2 + s
            verdict = self.isPossible(piles, h, mid)
            if verdict:
                e = mid-1
            else:
                s = mid+1
        return s
        