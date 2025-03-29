# https://leetcode.com/problems/partition-labels/

from typing import List

class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        hashmap = {} # char:last_most_occurence
        for i, c in enumerate(s):
            hashmap[c] = i

        res = []
        size,end = 0,0
        for i,c in enumerate(s):
            size += 1
            end = max(end, hashmap[c])
            if i == end:
                res.append(size)
                size = 0
        return res
