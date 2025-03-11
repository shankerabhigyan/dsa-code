# https://leetcode.com/problems/task-scheduler/description/

# heap/pq

import heapq
class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        if n==0:
            return len(tasks)
        task_counter = {}
        for task in tasks:
            if task not in task_counter:
                task_counter[task] = 1
            else:
                task_counter[task] += 1
        heap = []
        for item in task_counter:
            print(item)
            heapq.heappush(heap,-item[1])
        
        queue = []
        time_ = 0
        while len(heap)>0 or len(queue)>0:
            if len(queue>0) and time_>=queue[0][1]:
                heapq.heappush(queue[0][0])
            el = heapq.heappop(heap)
            queue.append([el+1,time_+2])
            time_+=1
        return time_
        
        