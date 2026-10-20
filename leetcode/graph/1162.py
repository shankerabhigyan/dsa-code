# https://leetcode.com/problems/as-far-from-land-as-possible/


class Solution:
	def maxDistance(self, grid: list[list[int]]) -> int:
		# traverse and keep a list of all land nodes,
		# add each land node's visited water node once using a viited list to ensure uniqueness
		# given nth iteration: n will be the answer
		queue = []
		n,m = len(grid), len(grid[0])
		for i in range(n):
			for j in range(m):
				if grid[i][j]==1:
					queue.append([i,j])

		if len(queue)==0 or len(queue)==n*m: return -1

		
		lvl=0
		while(len(queue)>0):
			nxt_queue=[]
			while(len(queue)>0):
				cell = queue.pop()
				dirns = [[1,0],[-1,0],[0,1],[0,-1]]
				for dirn in dirns:
					x,y = cell[0]+dirn[0], cell[1]+dirn[1]
					if 0<=x<n and 0<=y<m and grid[x][y]==0 and not grid[x][y]:
						nxt_queue.append([x,y])
						grid[x][y]=1

			queue = nxt_queue
			lvl+=1

		return lvl-1