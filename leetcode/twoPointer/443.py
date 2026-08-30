# https://leetcode.com/problems/string-compression/description/

from typing import List

class Solution:
  def compress(self, chars: List[str]) -> int:
    l,n,i=0,len(chars),0
    while(i<n):
      j=i+1
      while(j<n and chars[j]==chars[i]):
        j+=1
      chars[l]=chars[i]
      l+=1
      if(j-i>1):
        x=str(j-i)
        for idx in range(0,len(x)):
          chars[l]=x[idx]
          l+=1       
      i=j
    return l
          
        