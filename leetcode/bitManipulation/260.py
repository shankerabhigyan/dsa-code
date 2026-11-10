# https://leetcode.com/problems/single-number-iii/description/
# revisit
class Solution:
	def singleNumber(self, nums: list[int]) -> list[int]:
		x = 0
		for num in nums:
			x ^= num
		diffBit = x & -x
		x1,x2 = 0,0
		for num in nums:
			if num & diffBit:
				x1^=num
			else:
				x2^=num
		return [x1,x2]