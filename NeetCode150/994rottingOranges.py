# https://leetcode.com/problems/rotting-oranges/

from typing import List
from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = deque()
        num = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    q.append([i,j])
                    num+=1
                if grid[i][j] == 1:
                    num+=1
        
        # bfs
        ans = -1
        visited = [[0]*len(grid[0]) for _ in range(len(grid))]
        while len(q)>0:
            ans+=1
            x = len(q)
            num-=x 
            for i in range(x):
                top_i, top_j = q.popleft()
                visited[top_i][top_j] = 1
                checklist = [[+1,0],[-1,0],[0,+1],[0,-1]]
                for check in checklist:
                    newi,newj = top_i+check[0],top_j+check[1]
                    if 0<=newi<len(grid) and 0<=newj<len(grid[0]) and grid[newi][newj]==1 and visited[newi][newj]!=1:
                        q.append([newi,newj])
                        visited[newi][newj] = 1
        if num>0:
            return -1
        return max(ans,0)


