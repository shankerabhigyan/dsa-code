# https://leetcode.com/problems/course-schedule-ii/description/

from typing import List

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = [[] for i in range(numCourses)]
        for prereq in prerequisites:
            adj[prereq[0]].append(prereq[1])
        
        dp = [False]*numCourses

        temp = []
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
            temp.append(course)
            return True
        
        for i in range(numCourses):
            if dp[i]:
                continue
            else:
                visited = set()
                if dfs(i,visited)==False:
                    return []
        return temp
            

