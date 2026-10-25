# https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/

class Solution:
	def minimumFuelCost(self, roads: list[list[int]], seats: int) -> int:
		# thought process since the problem guarantees us 0 cycles, we identify all the leaf nodes and do a bfs on them
		# we are bound to reach ONLY the root and we stop when we do
		# so whats a leaf node? a node with only one attached edge that is NOT 0

		# leaf peeling
		
		n = len(roads)+1
		indegree = [0 for i in range(n)]
		adj = [[] for i in range(n)]
		for road in roads:
			adj[road[0]].append(road[1])
			adj[road[1]].append(road[0])
			indegree[road[0]]+=1
			indegree[road[1]]+=1

		queue = []
		ans=0
		for i in range(1,n):
			if indegree[i]==1:
				queue.append(i)
				indegree[i]-=1

		headcount = [1 for i in range(n)]
		visited = [0 for i in range(n)]
		while queue:
			curr = queue.pop()
			if curr:
				visited[curr]=1
				parent=-1
				for el in adj[curr]:
					if not visited[el]:
						indegree[el]-=1
						parent=el
				ans+=(headcount[curr]+seats-1)//seats
				headcount[parent]+=headcount[curr]
				if indegree[parent]==1:
					queue.append(parent)
		return ans