# https://leetcode.com/problems/reorder-list/description/

# Definition for singly-linked list.

class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def reorderList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: None Do not return anything, modify head in-place instead.
        """
        slow = head
        fast = head
        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next

        ListNode* prev = slow
        slow = slow.next
        while slow is not None:
            ListNode* temp = slow.next
            slow.next = prev
            prev = slow
            slow = temp
        
        # 1->2->3<-4<-5 OR 1->2->3<-4
        ListNode* p1 = head
        ListNode* p2 = prev

        while True:
            if p1==p2:
                break
            ListNode* temp = p1.next
            p1.next=p2
            p2 = temp
            p1 = p1.next

        return head