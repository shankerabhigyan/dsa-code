# https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

# HEAP/ PRIORITY QUEUE
import heapq

class KthLargest(object):

    def __init__(self, k, nums):
        """
        :type k: int
        :type nums: List[int]
        """
        self.heap = nums
        heapq.heapify(self.heap)

        while len(self.heap)>k:
            heapq.heappop(self.heap)                

    def add(self, val):
        """
        :type val: int
        :rtype: int
        """
        if len(self.heap)<self.k:
            heapq.heappush(self.heap,val)
        elif val>=self.heap[0]:
            heapq.heapreplace(self.heap,val)
        return self.heap[0]