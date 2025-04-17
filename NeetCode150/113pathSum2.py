# https://leetcode.com/problems/path-sum-ii/description/?envType=problem-list-v2&envId=backtracking

from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        ans = []
        def dfs(node:Optional[TreeNode], cur:List[int], cursum:int)->None:
            if node.left==None and node.right==None: # leaf node
                if cursum+node.val==targetSum:
                    cur.append(node.val)
                    ans.append(cur.copy())
                    cur.pop()
                return
            
            cur.append(node.val)

            if node.left is not None:
                dfs(node.left, cur, cursum+node.val)
    
            if node.right is not None:
                dfs(node.right, cur, cursum+node.val)

            cur.pop()
            
            return
        
        if not root:
            return ans
        dfs(root, [], 0)
        return ans