# https://leetcode.com/problems/number-of-islands/

from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        ans = 0
        visited = [[0]*len(grid[0]) for _ in range(len(grid))]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]=="1" and not visited[i][j]:
                    ans+=1
                    stack = []
                    stack.append([i,j])
                    visited[i][j]=1
                    while len(stack)>0:
                        x,y = stack[-1]
                        stack.pop()
                        checklist = [[x+1,y],[x,y+1],[x-1,y],[x,y-1]]
                        for idxx,idxy in checklist:
                            if idxx>=0 and idxy>=0 and idxx<len(grid) and idxy<len(grid[0]) and grid[idxx][idxy]=="1" and not visited[idxx][idxy]:
                                stack.append([idxx,idxy])
                                visited[idxx][idxy]=1
        
        return ans