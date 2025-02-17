import collections

class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        s = s.lower()
        t = t.lower()
        arr = [0]*26
        for ch in s:
            arr[ord(ch)-ord('a')] += 1
        for ch in t:
            if arr[ord(ch)-ord('a')]==0:
                return False
            arr[ord(ch)-ord('a')] -= 1
        return sum(arr)==0