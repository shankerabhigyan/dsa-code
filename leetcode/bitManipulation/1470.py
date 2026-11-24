# https://leetcode.com/problems/shuffle-the-array/description/

class Solution:
	def shuffle(self, nums: list[int], n: int) -> list[int]:
		for i in range(n):
			j = i+n
			nums[i] += nums[j]<<10
		for j in range(n-1,-1,-1):
			x,y = j*2,j*2+1
			nums[y]=nums[j]>>10
			nums[x]=nums[j]-(nums[y]<<10)

		return nums