# https://leetcode.com/problems/kth-smallest-element-in-a-bst/

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: Optional[TreeNode]
        :type k: int
        :rtype: int
        """
        stack = []
        temp = root
        n=0
        while temp or stack:
            while temp:
                stack.append(temp)
                temp = temp.left
            
            temp = stack.pop()
            n+=1
            if n==k:
                return temp.val
            temp = temp.right