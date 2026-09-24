
class Solution:
	def islandPerimeter(self, grid: list[list[int]]) -> int:
		perimeter = 0
		i,j = len(grid), len(grid[0])
		for x in range(i):
			for y in range(j):
				if grid[x][y]:
					perimeter+=4
					if x+1<i and grid[x+1][y]:
						perimeter-=1
					if x-1>=0 and grid[x-1][y]:
						perimeter-=1
					if y+1<j and grid[x][y+1]:
						perimeter-=1
					if y-1>=0 and grid[x][y-1]:
						perimeter-=1
		return perimeter
			