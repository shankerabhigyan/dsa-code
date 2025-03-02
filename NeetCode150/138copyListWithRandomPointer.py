"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if head is None:
            return head
        idxmap = {}
        temp = head
        length = 0
        while temp is not None:
            idxmap[temp] = length
            length+=1
            temp = temp.next
            
        newidxmap = {}
        temp = head
        for i in range(length):
            if i not in newidxmap:
                node = Node(temp.val)
                newidxmap[i] = node
            else:
                node = newidxmap[i]

            if temp.random is not None:
                if idxmap[temp.random] in newidxmap:
                    node.random = newidxmap[idxmap[temp.random]]
                else:
                    node.random = Node(temp.random.val)
                    newidxmap[idxmap[temp.random]] = node.random
            temp = temp.next

        for i in range(length-1):
            newidxmap[i].next = newidxmap[i+1]

        return newidxmap[0]