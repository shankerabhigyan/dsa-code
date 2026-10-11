# https://leetcode.com/problems/check-if-move-is-legal/description/

class Solution:
	def checkMove(self, board: list[list[str]], rMove: int, cMove: int, color: str) -> bool:
		n,m = len(board), len(board[0])
		oppColor = "W" if color=="B" else "B"
		directions = [[1,0],[0,1],[-1,0],[0,-1],[1,1],[-1,-1],[1,-1],[-1,1]]
		for dirn in directions:
			x,y = rMove+dirn[0], cMove+dirn[1]
			count=0
			while 0<=x<n and 0<=y<m and board[x][y]==oppColor:
				count+=1
				x,y = x+dirn[0], y+dirn[1]
			if 0<=x<n and 0<=y<m and board[x][y]==color and count>=1:
				return True
		return False