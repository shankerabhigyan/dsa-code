# https://leetcode.com/problems/last-stone-weight/description/

# HEAP/ PRIORITY_QUEUE

class Solution(object):
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        import heapq
        self.maxheap = [-val for val in stones]
        heapq.heapify(self.maxheap)

        while len(self.maxheap)>1:
            y = -heapq.heappop(self.maxheap)
            x = -heapq.heappop(self.maxheap)
            if x==y:
                continue
            else:
                heapq.heappush(self.maxheap,-(y-x))
        
        if len(self.maxheap)==0:
            return 0
        return -self.maxheap[0]
        