# https://leetcode.com/problems/generate-parentheses/description/

from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        def bcktrk(s, op, cl)->None:
            if len(s) == 2 * n:
                ans.append(s)
                return
            if op < n:
                bcktrk(s + '(', op + 1, cl)
            if cl < op:
                bcktrk(s + ')', op, cl + 1)
        bcktrk('', 0, 0)
        return ans