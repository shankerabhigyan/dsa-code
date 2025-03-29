# https://leetcode.com/problems/merge-triplets-to-form-target-triplet/description/

from typing import List

class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        map = [0,0,0]
        for triplet in triplets:
            if triplet[0]<=target[0] and triplet[1]<=target[1] and triplet[2]<=target[2]:
                if not map[0] and triplet[0]==target[0]:
                    map[0] = 1
                if not map[1] and triplet[1]==target[1]:
                    map[1] = 1
                if not map[2] and triplet[2]==target[2]:
                    map[2] = 1
                if map[0] and map[1] and map[2]:
                    return True
        return False