# https://leetcode.com/problems/trapping-rain-water/

class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n = len(height)
        maxleft = [0] * n
        maxright = [0] * n
        maxh = maxleft[0] = height[0]
        for i in range(1,n):
            maxleft[i] = maxh
            maxh = max(maxh,height[i])
        maxh = maxright[-1] = height[-1]
        for i in range(n-2,-1,-1):
            maxright[i] = maxh
            maxh = max(maxh,height[i])
        
        ans = 0
        for i in range(1,n):
            ans += max(0,min(maxleft[i],maxright[i])-height[i])
        return ans
    
class Solution(object): # OPTIMIZED - O(N)
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n = len(height)
        if n==2:
            return 0
        ans = 0
        l,r = 1, n-2
        maxleft = height[0]
        maxright = height[-1]
        while l<=r:
            if maxleft<=maxright:
                ans += max(0,maxleft-height[l])
                maxleft = max(maxleft,height[l])
                l+=1
            else:
                ans += max(0,maxright-height[r])
                maxright = max(maxright,height[r])
                r-=1

        return ans
        
            

if __name__=="__main__":
    height = list(map(int, input("Enter the heights separated by spaces: ").split()))
    solution = Solution()
    print("Trapped water:", solution.trap(height))
        