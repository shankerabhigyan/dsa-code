# https://leetcode.com/problems/subtree-of-another-tree/

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# class Solution(object):
#     def isSubtree(self, root, subRoot):
#         """
#         :type root: Optional[TreeNode]
#         :type subRoot: Optional[TreeNode]
#         :rtype: bool
#         """
#         self.nodes = [] 
#         self.findRoot(root,subRoot.val)
#         if len(self.nodes)==0:
#             return False
        
#         else:
#             for node in self.nodes:
#                 if self.isCopy(subRoot,node):
#                     return True
#             return False
        
#     def findRoot(self, root, val):
#         if root is not None:
#             if root.val==val:
#                 self.nodes.append(root)
#             self.findRoot(root.left,val)
#             self.findRoot(root.right, val)
            
#     def isCopy(self, r1, r2):
#         if r1 is None and r2 is None:
#             return True
#         if r1 is None or r2 is None:
#             return False
        
#         if r1.val==r2.val:
#             return self.isCopy(r1.left,r2.left) and self.isCopy(r1.right, r2.right)
#         return False

class Solution(object):
    def isSubtree(self, root, subRoot):
        if root is None:
            if subRoot is not None:
                return False
            return True
        if self.isCopy(root, subRoot):
            return True
        else:
            return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)

    def isCopy(self, r1, r2):
        if r1 is None and r2 is None:
            return True
        if r1 is None or r2 is None:
            return False
        
        if r1.val==r2.val:
            return self.isCopy(r1.left,r2.left) and self.isCopy(r1.right, r2.right)
        return False