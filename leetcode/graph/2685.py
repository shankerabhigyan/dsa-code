# https://leetcode.com/problems/count-the-number-of-complete-components/

class Solution:
	def countCompleteComponents(self, n: int, edges: list[list[int]]) -> int:
		visited = [0]*n
		adj = [[] for i in range(n)]
		for edge in edges:
			adj[edge[0]].append(edge[1])
			adj[edge[1]].append(edge[0])
		ans=0
		for i in range(n):
			if not visited[i]:
				edgeCount,elCount=0,1
				stack = [i]
				visited[i]=1
				while stack:
					top = stack.pop()
					for x in adj[top]:
						edgeCount+=1
						if not visited[x]:
							elCount+=1
							stack.append(x)
							visited[x]=1
				if edgeCount//2 == (elCount*(elCount-1))//2:
					ans+=1
		return ans
