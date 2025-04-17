# https://leetcode.com/problems/word-search/description/?envType=problem-list-v2&envId=backtracking

from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        y = len(board)
        x = len(board[0])
        visited = [[False for i in range(len(board[0]))] for j in range(len(board))]
        def dfs(idx, curr):
            if idx==len(word):
                return True
            ch = word[idx]
            i,j = curr
            if i-1>=0 and board[i-1][j]==ch and not visited[i-1][j]:
                visited[i-1][j] = True
                if dfs(idx+1, [i-1,j]):
                    return True
                visited[i-1][j] = False

            if i+1<y and board[i+1][j]==ch and not visited[i+1][j]:
                visited[i+1][j] = True
                if dfs(idx+1, [i+1,j]):
                    return True
                visited[i+1][j] = False
            
            if j+1<x and board[i][j+1]==ch and not visited[i][j+1]:
                visited[i][j+1] = True
                if dfs(idx+1,[i,j+1]):
                    return True
                visited[i][j+1] = False
            
            if j-1>=0 and board[i][j-1]==ch and not visited[i][j-1]:
                visited[i][j-1] = True
                if dfs(idx+1, [i,j-1]):
                    return True
                visited[i][j-1] = False
            
        start = []
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j]==word[0]:
                    start.append([i,j])
        
        for pts in start:
            visited[pts[0]][pts[1]] = True
            if dfs(1,pts):
                return True
            visited[pts[0]][pts[1]] = False
            
        return False
            
