# https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

# HEAP/ PRIORITY QUEUE
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
        heapq.heapify(heap)
        for item,key in task_counter.items():
            heapq.heappush(heap,-key)
        
        queue = []
        time_ = 0
        while len(heap)>0 or len(queue)>0:
            if len(heap)==0:
                time_ = queue[0][1]
            if len(queue)>0 and time_>=queue[0][1]:
                heapq.heappush(heap,queue[0][0])
                queue.pop(0)
            el = heapq.heappop(heap)
            if el<-1:
                queue.append([el+1,time_+n+1])
            time_+=1
        return time_