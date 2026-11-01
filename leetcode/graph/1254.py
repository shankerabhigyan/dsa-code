# https://leetcode.com/problems/number-of-closed-islands/

class Solution:
	def dfs(self, grid,queue,x,y):
		while queue:
			xx,yy = queue.pop()
			for dx,dy in [[1,0],[0,1],[-1,0],[0,-1]]:
				if 0<=xx+dx<x and 0<=yy+dy<y and grid[xx+dx][yy+dy]==0:
					grid[xx+dx][yy+dy]=1
					queue.append((xx+dx,yy+dy))

	def closedIsland(self, grid: list[list[int]]) -> int:
		# we will discard all islands with any land on the edge as they are not closed
		x,y = len(grid), len(grid[0])
		for xx in [0,x-1]:
			for yy in range(y):
				if grid[xx][yy]==0:
					grid[xx][yy]=1
					self.dfs(grid,[(xx,yy)],x,y)
					
		for yy in [0,y-1]:
			for xx in range(1,x-1):
				if grid[xx][yy]==0:
					grid[xx][yy]=1
					self.dfs(grid,[(xx,yy)],x,y)

		count=0
		for i in range(1,x-1):
			for j in range(1,y-1):
				if grid[i][j]==0:
					count+=1
					grid[i][j]=1
					self.dfs(grid,[(i,j)],x,y)

		return count