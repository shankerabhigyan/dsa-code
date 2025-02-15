import collections

# https://leetcode.com/problems/set-matrix-zeroes/?envType=problem-list-v2&envId=hash-table

class Solution(object): 
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        rows = collections.defaultdict(int)
        cols = collections.defaultdict(int)
        for r in range(len(matrix)):
            for c in range(len(matrix[0])):
                if(matrix[r][c]==0):
                    rows[r]=1
                    cols[c]=1

        for r in range(len(matrix)):
            for c in range(len(matrix[0])):
                if(rows[r] or cols[c]):
                    matrix[r][c]=0

# Time complexity: O(m*n)
# Space complexity: O(m+n)

# O(1) space solution

class Solution(object):
    def setZeroes(self,matrix):
        extra = False

        for r in range(len(matrix)):
            for c in range(1, len(matrix[0])):
                if(matrix[r][c]==0):
                    matrix[0][c]=0
                    if r>0:
                        matrix[r][0]=0
                    else:
                        extra = True

        for r in range(1, len(matrix)):
            for c in range(1, len(matrix[0])):
                if(matrix[0][c]==0 or matrix[r][0]==0):
                    matrix[r][c]=0

        if(matrix[0][0]==0):
            for r in range(len(matrix)):
                matrix[r][0]=0

            

        