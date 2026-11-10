# https://leetcode.com/problems/detonate-the-maximum-bombs/description/

class Solution:
	def getDist(self,x1,y1,x2,y2)->int:
		return pow(x1-x2,2)+pow(y1-y2,2)
	def maximumDetonation(self, bombs: list[list[int]]) -> int:
		n=len(bombs)
		adj = [[] for i in range(n)]
		for i in range(n):
			for j in range(0,i):
				dist = self.getDist(bombs[i][0],bombs[i][1],bombs[j][0],bombs[j][1])
				if bombs[i][2]**2>=dist:
					# means j is in i's radius
					adj[i].append(j)
				if bombs[j][2]**2>=dist:
					adj[j].append(i)

		ans=0
		for i in range(n):
			visited=set()
			stack=[i]
			visited.add(i)
			while stack:
				top = stack.pop()
				for j in adj[top]:
					if j not in visited:
						visited.add(j)
						stack.append(j)
			ans = max(ans,len(visited))

		return ans
