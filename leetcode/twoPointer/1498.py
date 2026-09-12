# https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
from typing import List
class Solution:
	def numSubseq(self, nums: List[int], target: int) -> int:
		nums.sort()
		n=len(nums)
		ans=0
		r=n-1
		MOD = 10**9+7
		for l in range(n):
			while(l<=r):
				if(nums[l]+nums[r]<=target):
					x = r-l
					x = pow(2,x,MOD)
					ans+=x
					ans = ans%MOD
					break
				r-=1
		return ans