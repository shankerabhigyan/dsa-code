# https://leetcode.com/problems/regions-cut-by-slashes/description/

class Solution:
	def traversal(self, adj,x,n2,visitedEl,visitedEdge):
		ans=0
		q = [x]
		
		while q:
			top = q.pop()
			for i in adj[top]:
				if (top,i) not in visitedEdge:
					if visitedEl[i]:
						ans+=1
					else:
						q.append(i)
						visitedEl[i]=1
					visitedEdge.add((top,i))
					visitedEdge.add((i,top))
		return ans

	def regionsBySlashes(self, grid: list[str]) -> int:
		n = len(grid[0])
		n2 = (n+1)**2

		k = n**2 + n
		adj = [[] for i in range(n2)]
		for i in range(0,n):
			adj[i].append(i+1)
			adj[i+1].append(i)	
			adj[i+k].append(i+k+1)
			adj[i+k+1].append(i+k)
		
		for i in range(0,k,n+1):
			adj[i].append(i+n+1)
			adj[i+n+1].append(i)
			adj[i+n].append(i+2*n+1)
			adj[i+n*2+1].append(i+n)

		for i in range(n):
			for j in range(n):
				x=i*(n+1)+j
				if grid[i][j]!=' ':
					if grid[i][j]=='/':
						adj[x+n+1].append(x+1)
						adj[x+1].append(x+n+1)
					else:
						adj[x].append(x+n+2)
						adj[x+n+2].append(x)

		visitedEl = [0]*n2
		visitedEl[0]=1
		visitedEdge = set()
		ans = self.traversal(adj,0,n2,visitedEl,visitedEdge)
		for i in range(n):
			for j in range(n):
				el = i*(n+1)+j
				if not visitedEl[el] and grid[i][j]!=' ':
					ans+=self.traversal(adj,el,n2,visitedEl,visitedEdge)

		return ans