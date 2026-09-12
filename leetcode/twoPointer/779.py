# https://leetcode.com/problems/k-th-symbol-in-grammar/description/

class Solution:
	def kthGrammar(self, n: int, k: int) -> int:
		if k==1:
			return 0
		elif k%2==0:
			return 1-self.kthGrammar(n-1,k//2)
		else:
			return self.kthGrammar(n-1,(k+1)//2)