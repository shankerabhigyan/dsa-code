# https://leetcode.com/problems/number-of-islands/description/

from typing import List


class Solution:
	def dfs(self,grid,n,m):
		stack=[]
		rows,cols = len(grid),len(grid[0])
		stack.append([n,m])
		while stack:
			top = stack.pop()
			mat = [[1,0],[-1,0],[0,1],[0,-1]]
			for dx,dy in mat:
				i,j = top[0]+dx, top[1]+dy
				if i>=0 and j>=0 and i<rows and j<cols and grid[i][j] == '1':
					grid[i][j] = '0'
					stack.append([i,j])

	def numIslands(self, grid: List[List[str]]) -> int:
		# we traverse each element, everytime we get an unvisited '1' we run a search and mark all accessible '1' as visited,
		# increment the island count to 1 after each search
		rows,cols = len(grid),len(grid[0])
		islands=0
		for n in range(rows):
			for m in range(cols):
				if grid[n][m] == '1':
					self.dfs(grid,n,m)
					islands+=1
		return islands