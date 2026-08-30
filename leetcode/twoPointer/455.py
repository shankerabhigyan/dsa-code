from typing import List

class Solution:
  def findContentChildren(self, g: List[int], s: List[int]) -> int:
    g = sorted(g)
    s = sorted(s)
    x,y,a,b = 0,0,len(g),len(s)
    ans = 0
    while(x<a and y<b):
      if(g[x]<=s[y]):
        ans+=1
        x+=1
        y+=1
      else:
        y+=1
    return ans