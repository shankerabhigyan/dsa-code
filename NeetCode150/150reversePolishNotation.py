# https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/1590822872/

from typing import List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for tok in tokens:
            if tok.lstrip('-').isdigit():
                stack.append(int(tok))
            else:
                if tok=='+':
                    stack.append(stack.pop()+stack.pop())
                elif tok=='-':
                    stack.append(-stack.pop()+stack.pop())
                elif tok=='*':
                    stack.append(stack.pop()*stack.pop())
                else:
                    stack.append(1/stack.pop()*stack.pop())
        return stack[0]