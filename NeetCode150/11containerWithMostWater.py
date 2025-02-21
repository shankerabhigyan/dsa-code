# https://leetcode.com/problems/container-with-most-water/

class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        ans = 0
        l = 0
        r = len(height)-1
        while l<r:
            ans = max(ans,min(height[l],height[r])*(l-r))
            if height[l]<height[r]:
                l+=1
            else:
                r-=1
        return ans
            
