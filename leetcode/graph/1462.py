# https://leetcode.com/problems/course-schedule-iv/

class Solution:
	def dfs(self, n, adj, memoiz,visited):
		if visited[n]:
			return memoiz[n]
		else:
			visited[n]=True
			memoiz[n].add(n)
			for course in adj[n]:
				memoiz[n] = memoiz[n].union(self.dfs(course,adj,memoiz,visited))
			return memoiz[n]

	def checkIfPrerequisite(self, numCourses: int, prerequisites: list[list[int]], queries: list[list[int]]) -> list[bool]:
		adj = [[] for _ in range(numCourses)]
		memoiz = [set() for _ in range(numCourses)]
		visited = [False]*numCourses

		for prereq in prerequisites:
			adj[prereq[0]].append(prereq[1])
		
		for i in range(numCourses):
			self.dfs(i,adj,memoiz,visited)
		ans = [False]*len(queries)
		for i in range(len(queries)):
			query = queries[i]
			if query[1] in memoiz[query[0]]:
				ans[i]=True

		return ans