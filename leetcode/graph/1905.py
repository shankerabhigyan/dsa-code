# https://leetcode.com/problems/count-sub-islands/description/

class Solution:
	def dfs(self,grid2,grid1,i,j):
		stack=[]
		flag=True
		stack.append([i,j])
		grid2[i][j]=0
		while stack:
			top = stack.pop()
			if grid1[top[0]][top[1]]!=1:
				flag=False
			for dx,dy in [[1,0],[-1,0],[0,1],[0,-1]]:
				x,y = top[0]+dx, top[1]+dy
				if x>=0 and y>=0 and x<len(grid2) and y<len(grid2[0]) and grid2[x][y]==1:
					stack.append([x,y])
					grid2[x][y]=0
		if flag:
			return 1
		return 0
	def countSubIslands(self, grid1: list[list[int]], grid2: list[list[int]]) -> int:
		rows, cols = len(grid1), len(grid1[0])
		count=0
		for i in range(rows):
			for j in range(cols):
				if grid2[i][j]==1:
					count+=self.dfs(grid2,grid1,i,j)
		return count