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
        