from typing import List
class Solution:
	def dfs(self,grid,n,m)-> int:
		rows,cols = len(grid),len(grid[0])
		stack,fishes=[],0
		stack.append([n,m])
		fishes+=grid[n][m]
		grid[n][m]=0
		while stack:
			top = stack.pop()
			for dx,dy in [[1,0],[-1,0],[0,1],[0,-1]]:
				i,j = top[0]+dx, top[1]+dy
				if i>=0 and j>=0 and i<rows and j<cols and grid[i][j]>0:
					fishes+=grid[i][j]
					grid[i][j]=0
					stack.append([i,j])
		return fishes
	def findMaxFish(self, grid: List[List[int]]) -> int:
		rows,cols = len(grid),len(grid[0])
		fishes = 0
		for n in range(rows):
			for m in range(cols):
				if grid[n][m]>0:
					fishes = max(fishes,self.dfs(grid,n,m))
		return fishes