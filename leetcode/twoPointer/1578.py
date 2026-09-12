# https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/

from typing import List


class Solution:
	def minCost(self, colors: str, neededTime: List[int]) -> int:
		i,n=0,len(colors)
		ans=0
		while(i<n):
			j=i
			costMax = 0
			costSum=0
			while(j<n and colors[j]==colors[i]):
				costMax = max(costMax,neededTime[j])
				costSum+=neededTime[j]
				j+=1
			if j-i>1:
				ans+=costSum-costMax
			i=j
		return ans