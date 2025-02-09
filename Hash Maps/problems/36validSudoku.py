# https://leetcode.com/problems/valid-sudoku/?envType=problem-list-v2&envId=hash-table

import collections

class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        cols = collections.defaultdict(set)
        rows = collections.defaultdict(set) # hash sets
        squares = collections.defaultdict(set) # key = r/3, c/3

        for r in range(9):
            for c in range(9):
                if board[r][c] == ".":
                    continue # skip if empty space

                if(board[r][c] in rows[r] or board[r][c] in cols[c] or board[r][c] in squares[(r//3, c//3)]):
                    return False
                
                cols[c].add(board[r][c])
                rows[r].add(board[r][c])
                squares[(r//3, c//3)].add(board[r][c])

        return True
        
        