# https://leetcode.com/problems/valid-parentheses/

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        hashmap = {
            '(': ')',
            '{': '}',
            '[': ']'
        }

        for c in s:
            if c in hashmap:
                stack.append(c)
            else:
                if not stack or c != hashmap[stack.pop()]:
                    return False
        return not stack