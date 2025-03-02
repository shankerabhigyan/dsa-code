# https://leetcode.com/problems/merge-k-sorted-lists/description/

import heapq

class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[Optional[ListNode]]
        :rtype: Optional[ListNode]
        """
        tmp = ListNode(0)
        head = tmp
        heap = []
        for l in lists:
            if l is not None:
                heapq.heappush(heap,(l.val, l))
        
        while len(heap)>0:
            _,node = heapq.heappop(heap)
            tmp.next = node
            if node.next is not None:
                heapq.heappush(heap, (node.next.val, node.next))
            tmp = tmp.next

        return head.next