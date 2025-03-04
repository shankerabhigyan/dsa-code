# https://leetcode.com/problems/diameter-of-binary-tree/description/

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        _,ans = self.solve(root)
        return ans
    
    def solve(self, node):
        if node is None:
            return (0,0)
        
        left, left_ans = self.solve(node.left)
        right, right_ans = self.solve(node.right)

        curr_ans = max(1 + left + right,max(left_ans,right_ans))
        
        return (1+max(left,right),curr_ans)
        