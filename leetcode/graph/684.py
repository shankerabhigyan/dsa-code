
class Solution:
	def findRoot(self,representative,x):
		if x==representative[x]:
			return x
		else:
			root = self.findRoot(representative, representative[x])
			representative[x] = root # path compression
			return root

	def findRedundantConnection(self, edges: list[list[int]]) -> list[int]:
		## union find
		representative = [i for i in range(len(edges)+2)] # n nodes result in n-1 edges + 1 wrong index // 1-indexed
		## leads to [0,1,2,3...n] which means that every node initially is a representative of itself
		size = [1 for i in range(len(edges)+2)]
		for e in edges:
			rep0, rep1 = self.findRoot(representative, e[0]), self.findRoot(representative, e[1])
			if rep0==rep1:
				return e
			else:
				if size[rep0]>size[rep1]:
					representative[rep1] = rep0
					size[rep0]+=size[rep1]
				else:
					representative[rep0] = rep1
					size[rep1]+=size[rep0]
				
