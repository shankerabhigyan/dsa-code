class Solution:
	def minBitFlips(self, start: int, goal: int) -> int:
		ans=0
		while start>0 or goal>0:
			ans+=(start&1)^(goal&1)
			start = start>>1
			goal = goal>>1
		return ans