# https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/


class Solution:
	def minScore(self, n: int, roads: list[list[int]]) -> int:
		adj = [[] for i in range(n+1)]
		for road in roads:
			adj[road[0]].append((road[1],road[2]))
			adj[road[1]].append((road[0],road[2]))

		stack=[1]

		ans =float('inf')
		visited = [0] * (n+1)
		visited[1] = 1

		while stack:
			top = stack.pop()
			for x,dist in adj[top]:
				ans = min(ans,dist)
				if not visited[x]:
					stack.append(x)
					visited[x]=1

		return ans