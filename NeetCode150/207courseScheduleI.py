# https://leetcode.com/problems/course-schedule/description/

from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = [[] for i in range(numCourses)]
        for prereq in prerequisites:
            adj[prereq[1]].append(prereq[0])

        dp = [False]*numCourses

        def dfs(course, visited):
            if dp[course]:
                return True
            if course in visited:
                return False
            visited.add(course)
            if len(adj[course])>0:
                for it in adj[course]:
                    if not dfs(it, visited):
                        return False
            visited.remove(course)
            dp[course]=True
            return True
        
        for i in range(numCourses):
            if dp[i]:
                continue
            else:
                visited = set()
                if dfs(i,visited)==False:
                    return False
        return True