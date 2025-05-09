# https://leetcode.com/problems/climbing-stairs/

class Solution:
    def climbStairs(self, n: int) -> int:
        dp = []*n
        dp[n-1] = 1
        dp[n-2] = 2
        for i in range(n-3,0,-1):
            dp[i] =  dp[i+1] + dp[i+2]

        return dp[0]