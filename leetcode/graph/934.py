# https://leetcode.com/problems/shortest-bridge/description/

from collections import deque

class Solution:
	def getFirstCell(self,grid):
		for i in range(len(grid)):
			for j in range(len(grid[0])):
				if grid[i][j]==1:
					return i,j
		return 0,0
	
	def bfs(self,grid,i,j):
		queue = []
		idx=0
		queue.append([i,j])
		grid[i][j]=2
		dirs = [[1,0],[-1,0],[0,1],[0,-1]]
		while idx<len(queue):
			top = queue[idx]
			idx+=1
			for dir in dirs:
				x,y = top[0]+dir[0], top[1]+dir[1]
				if 0<=x<len(grid) and 0<=y<len(grid[0]) and grid[x][y]==1:
					queue.append([x,y])
					grid[x][y]=2
		return queue

	def shortestBridge(self, grid: list[list[int]]) -> int:
		i,j = self.getFirstCell(grid)
		queue = self.bfs(grid,i,j)
		queue1 = deque([])
		for cell in queue:
			queue1.append([0,cell[0],cell[1]])
		dirs = [[1,0],[-1,0],[0,1],[0,-1]]
		while queue1:
			top = queue1.popleft()
			for dir in dirs:
				x,y = top[1]+dir[0], top[2]+dir[1]
				if 0<=x<len(grid) and 0<=y<len(grid[0]):
					if grid[x][y]==1:
						return top[0]
					elif grid[x][y]==0:
						queue1.append([top[0]+1,x,y])
						grid[x][y]=2
