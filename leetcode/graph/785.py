# https://leetcode.com/problems/is-graph-bipartite/description/

class Solution:
	def isBipartite(self, graph: list[list[int]]) -> bool:
		n = len(graph)
		visited = [0]*n
		tracker = [set(),set()]
		for i in range(n):
			if not visited[i]:
				visited[i]=1
				tracker[0].add(i)
				stack=[(i,0)]
				while stack:
					top,idx = stack.pop()
					for x in graph[top]:
						if x in tracker[idx]:
							return False
						if not visited[x]:
							tracker[1-idx].add(x)
							stack.append((x,1-idx))
							visited[x]=1

		return True
