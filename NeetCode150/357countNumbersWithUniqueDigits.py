# https://leetcode.com/problems/count-numbers-with-unique-digits/description/?envType=problem-list-v2&envId=backtracking

class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        hashmap = {}
        for i in range(0,9):
            hashmap[i] = False
        
        res = []
        def count(i):
            