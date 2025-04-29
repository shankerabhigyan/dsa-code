# https://leetcode.com/problems/pacific-atlantic-water-flow/description/

from typing import List

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        rows,cols = len(heights), len(heights[0])
        