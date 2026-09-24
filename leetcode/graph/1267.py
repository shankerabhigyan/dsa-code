class Solution:
	def countServers(self, grid: list[list[int]]) -> int:
		rows,cols = len(grid),len(grid[0])
		res=0
		for i in range(rows):
			rowSum = sum(grid[i])
			if rowSum>1:
				res+=rowSum
				for j in range(cols):
					if grid[i][j]:
						grid[i][j]=-1

		for j in range(cols):
			summ, newSrvr = 0,0
			for i in range(rows):
				summ+=abs(grid[i][j])
				if grid[i][j]>0:
					newSrvr+=1
			if summ>1:
				res+=newSrvr
		return res