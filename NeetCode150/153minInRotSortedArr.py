# https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
# BINARY SEARCH

class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        s=0
        e = len(nums)-1
        
        while s<e:
            mid = (e-s)//2 + s
            print(s,e,mid)
            if nums[s]<nums[mid] and nums[mid]<nums[e]:
                return nums[s]   
            if nums[mid]>nums[e]:
                s = mid+1
            else:
                e = mid
        return nums[s]

