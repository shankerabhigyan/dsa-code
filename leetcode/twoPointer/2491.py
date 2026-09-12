from collections import List

# https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/
class Solution:
  def getsum(self, skill:List[int]) -> int:
    summ=0
    for i in range(len(skill)):
      summ+=skill[i]
    return int(summ)
  def dividePlayers(self, skill: List[int]) -> int:
    hashmap = {}
    summ = self.getsum(skill)/(len(skill)/2)
    ans=0
    for i in range(len(skill)):
      if skill[i] in hashmap:
        ans+= skill[i]*(summ-skill[i])
        hashmap[skill[i]]-=1
        if hashmap[skill[i]]==0:
          hashmap.pop(skill[i])
      else:
        x = summ-skill[i]
        if x in hashmap:
          hashmap[x]+=1
        else:
          hashmap[x]=1
    if(len(hashmap)>0):
        return -1
    return int(ans)