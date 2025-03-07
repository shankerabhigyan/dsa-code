# https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def goodNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.dfs(root, root.val)
    
    def dfs(self, node, prev):
        if node is None:
            return 0
        
        if node.val >= prev:
            prev = node.val
            return 1 + self.dfs(node.left, prev) + self.dfs(node.right, prev)
        else:
            return self.dfs(node.left, prev) + self.dfs(node.right, prev)