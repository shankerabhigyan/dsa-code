# https://leetcode.com/problems/unique-binary-search-trees-ii/description/?envType=problem-list-v2&envId=backtracking

from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        def generate(left,right):
            if left==right:
                return [TreeNode(left)]
            if left>right:
                return [None]
            
            res = []
            for val in range(left,right+1):
                for leftTree in generate(left,val-1):
                    for rightTree in generate(val+1,right):
                        root = TreeNode(val,leftTree,rightTree)
                        res.append(root)
            return res
        return generate(1,n)