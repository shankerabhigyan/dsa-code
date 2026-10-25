class Solution:
	def shortestAlternatingPaths(self, n: int, redEdges: list[list[int]], blueEdges: list[list[int]]) -> list[int]:
		# red=0, blue=1
		adj =[[[],[]] for i in range(n)]
		for i in range(2):
			edges = redEdges if i==0 else blueEdges
			for edge in edges:
				adj[edge[0]][i].append(edge[1])

		ans = [-1 for i in range(n)]
		ans[0]=0
		queue=[]
		dist=1
		visited = [[0,0] for i in range(n)] # [visited via red edge, visited via blue edge]

		for i in range(2):
			for node in adj[0][i]:
				queue.append([node, 1-i]) # [node#, expected next edge color]
				visited[node][i]=1
		
		while(len(queue)):
			nextQueue = []
			while(len(queue)):
				top = queue.pop()
				node, expectedColor = top[0], top[1]
				if ans[node]==-1:
					ans[node]=dist
				for nextNode in adj[node][expectedColor]:
					if visited[nextNode][expectedColor]:
						continue
					else:
						nextQueue.append([nextNode,1-expectedColor])
						visited[nextNode][expectedColor]=1
			queue = nextQueue
			dist+=1
		return ans