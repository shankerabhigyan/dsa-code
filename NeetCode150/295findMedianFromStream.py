# https://leetcode.com/problems/find-median-from-data-stream/description/

import heapq

class MedianFinder(object):

    def __init__(self):
        self.heapLeft = []
        self.heapRight = []
        self.len = 0

    def addNum(self, num):
        """
        :type num: int
        :rtype: None
        """
        self.len+=1
        if len(self.heapLeft)==len(self.heapRight):
            heapq.heappush(self.heapLeft,-num)
        else:
            heapq.heappush(self.heapRight,num)
        
        while len(self.heapRight) and -self.heapLeft[0] > self.heapRight[0]:
            el1 = -heapq.heappop(self.heapLeft)
            el2 = heapq.heappop(self.heapRight)
            heapq.heappush(self.heapLeft,-el2)
            heapq.heappush(self.heapRight,el1)

    def findMedian(self):
        """
        :rtype: float
        """
        if self.len>0:
            if self.len%2==0:
                return (-self.heapLeft[0] + self.heapRight[0])/2
            else:
                return -self.heapLeft[0]


        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()