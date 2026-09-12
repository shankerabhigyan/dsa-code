from collections import List
# https://leetcode.com/problems/boats-to-save-people/

class Solution:
  def numRescueBoats(self, people: List[int], limit: int) -> int:
    people.sort()
    i,j,cnt=0,len(people)-1,0
    while(i<=j):
      if people[i]+people[j]<=limit:
        cnt+=1
        i+=1
        j-=1
      else:
        j-=1
        cnt+=1
    return cnt