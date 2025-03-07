# https://leetcode.com/problems/validate-binary-search-tree/description/

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        if root is None:
            return True
        return self.isValidBSTRec(root, None, None)
    
    def isValidBSTRec(self, root, minNode, maxNode):
        if root is None:
            return True
        if minNode is not None and root.val <= minNode.val:
            return False
        if maxNode is not None and root.val >= maxNode.val:
            return False
        return self.isValidBSTRec(root.left, minNode, root) and self.isValidBSTRec(root.right, root, maxNode)