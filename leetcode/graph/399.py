# https://leetcode.com/problems/evaluate-division/


class Solution:
	def dfs(self,adj,a,b):
		if a==b:
			return 1.0
		stack,vis = [(a,1.0)],set()
		vis.add(a)
		while stack:
			el,fac = stack.pop()
			for n,facc in adj[el]:
				if n not in vis:
					if n==b:
						return fac*facc
					stack.append((n,fac*facc))
					vis.add(n)
		return -1.0
		
	def calcEquation(self, equations: list[list[str]], values: list[float], queries: list[list[str]]) -> list[float]:
		adj = {}
		poww = [1,-1]
		for i in range(len(values)):
			for j in range(2):
				if equations[i][j] not in adj:
					adj[equations[i][j]]=[]
				adj[equations[i][j]].append((equations[i][1-j],pow(values[i],poww[j])))
		ans = [-1.0]*len(queries)
		for i in range(len(queries)):
			q = queries[i]
			if q[0] in adj and q[1] in adj:
				ans[i] = self.dfs(adj,q[0],q[1])
		return ans
