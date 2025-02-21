# https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        x,y = 0, len(numbers)-1
        while x<y:
            if numbers[x]+numbers[y]==target:
                return [x+1,y+1]
            if numbers[x]+numbers[y]>target:
                y-=1
            if numbers[x]+numbers[y]<target:
                x+=1

            