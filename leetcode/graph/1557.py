# https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/

class Solution:
	def findSmallestSetOfVertices(self, n: int, edges: list[list[int]]) -> list[int]:
		indegrees = [0]*n
		for edge in edges:
			indegrees[edge[1]]+=1
		ans=[]
		for i in range(n):
			if indegrees[i]==0:
				ans.append(i)

		return ans