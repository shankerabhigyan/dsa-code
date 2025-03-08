# https://leetcode.com/problems/k-closest-points-to-origin/

# HEAP/PQ

class Solution(object):
    def kClosest(self, points, k):
        """
        :type points: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        import heapq
        heap = []
        for i in range(k):
            heapq.heappush(heap,[-points[i][0]**2 - points[i][1]**2,points[i]])

        for i in range(k,len(points)):
            if -heap[0][0]>points[i][0]**2 + points[i][1]**2:
                heapq.heappop(heap)
                heapq.heappush(heap,[-points[i][0]**2 - points[i][1]**2,points[i]])

        return [x[1] for x in heap]