# https://leetcode.com/problems/product-of-array-except-self/


class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # O(n) time and without using the division operator
        output = [1]*len(nums)
        pre = nums[0]
        for i in range(1,len(nums)):
            output[i] = pre
            pre *= nums[i]
        post = nums[-1]
        for i in range(len(nums)-2,1,-1):
            output[i] *= post
            post *= nums[i]

        return output
