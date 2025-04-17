# https://leetcode.com/problems/restore-ip-addresses/description/?envType=problem-list-v2&envId=backtracking

from typing import List

class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        ans = []
        if len(s)<4 or len(s)>12:
            return ans
        
        def backtrack(i, dots, currIP):
            if dots==4 and i==len(s):
                ans.append(currIP[:-1])
                return
            if dots>4:
                return
            
            for x in range(i, min(i+3,len(s))):
                if int(s[i:x+1])<=255 and (i==x or s[i]!='0'):
                    backtrack(x+1, dots+1, currIP+s[i:x+1]+'.')

        backtrack(0,0,"")
        return ans