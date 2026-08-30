class Solution:
    def minLengthAfterRemovals(self, s: str) -> int:
        count = [0,0]
        for ch in s:
            count[ord(ch)-ord('a')]+=1
        return max(count[0],count[1])-min(count[0],count[1])
