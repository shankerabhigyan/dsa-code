# https://leetcode.com/problems/additive-number/description/?envType=problem-list-v2&envId=backtracking

class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        n = len(num)

        def is_valid(num, idx, first, second):
            if idx==n:
                return True
            
            nextSum = str(first+second)
            if idx+len(nextSum)>n:
                return False
            
            if num[idx:idx+len(nextSum)]!=nextSum:
                return False
            
            return is_valid(num, idx+len(nextSum), second, first+second)

        for i in range(1,n//2+1):
            if num[0]=='0' and i>1:
                continue
            for j in range(1,(n-i)//2+1):
                if num[i]=='0' and j>1:
                    continue
                first = int(num[:i])
                second = int(num[i:i+j])

                if is_valid(num, i+j, first,second):
                    return True
        return False
            
