# https://leetcode.com/problems/jump-game-ii/description/

class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==1:
            return 0
        visited = {}
        queue = []
        queue.append([0,0])
        while len(queue)>0:
            i,dist = queue.pop(0)
            if i not in visited:
                visited[i] = True
                for idx in range(i+1,min(i+nums[i],len(nums)-1)+1):
                    if idx==len(nums)-1:
                        return dist+1
                    if idx not in visited:
                        queue.append([idx,dist+1])
                    