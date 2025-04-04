# https://leetcode.com/problems/largest-rectangle-in-histogram/description/

from typing import List

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        maxArea = 0
        for idx, height in enumerate(heights):
            start = idx
            while stack and height < stack[-1][1]:
                i, h = stack.pop()
                maxArea = max(maxArea, h * (idx - i))
                start = i 
            stack.append([start, height])
        
        i = len(heights)
        while stack:
            idx, height = stack.pop()
            maxArea = max(maxArea, height * (i - idx))
        
        return maxArea
