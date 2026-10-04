# https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/

class Solution:
	def minReorder(self, n: int, connections: list[list[int]]) -> int:
		graph = [[] for _ in range(n)]
		for a, b in connections:
			graph[a].append((b, 1))  # a -> b, traversing away from 0 costs a flip
			graph[b].append((a, 0))  # reverse entry, free

		count = 0
		stack = [(0, -1)]  # (node, parent)
		while stack:
			node, parent = stack.pop()
			for nei, cost in graph[node]:
				if nei != parent:
					count += cost
					stack.append((nei, node))
		return count
	