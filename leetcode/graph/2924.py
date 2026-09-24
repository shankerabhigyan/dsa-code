from typing import List

class Solution:
	def findChampion(self, n: int, edges: List[List[int]]) -> int:
		incoming = [0]*n
		for edge in edges:
			incoming[edge[1]]+=1
		cnt,champion=0,-1
		for i in range(n):
			if incoming[i]==0:
				if cnt==1:
					return -1
				cnt+=1
				champion=i
		return champion