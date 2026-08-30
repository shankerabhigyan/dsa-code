from typing import List

class Solution:
  def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
    ans = []
    i,j,ni,nj = 0,0,len(nums1),len(nums2)
    while(i<ni and j<nj):
      if(nums1[i][0]<nums2[j][0]):
        ans.append(nums1[i])
        i+=1
      elif(nums1[i][0]==nums2[j][0]):
        ans.append([nums1[i][0],nums1[i][1]+nums2[j][1]])
        i,j = i+1,j+1
      else:
        ans.append(nums2[j])
        j+=1
    
    while(i<ni):
      ans.append(nums1[i])
      i+=1
    while(j<nj):
      ans.append(nums2[j])
      j+=1
    
    return ans
    