from typing import List

class Solution:
	def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
		nums.sort()
		ans = []
		n = len(nums)
		for i in range(n-3):
			if i>0 and nums[i]==nums[i-1]:
				continue
			j=i+1
			while j<n-2:
				k,l=j+1,n-1
				while(k<l):
					summ = nums[i] + nums[j] + nums[k] + nums[l]
					if summ==target:
						ans.append([nums[i], nums[j], nums[k],nums[l]])
						while(k<l and nums[k+1]==nums[k]):
							k+=1
						while(l>k and nums[l-1]==nums[l]):
							l-=1
						k,l=k+1,l-1
					elif summ<target:
						k+=1
					else:
						l-=1
				while j<n-2 and nums[j+1]==nums[j]:
					j+=1
				j+=1
		return ans
