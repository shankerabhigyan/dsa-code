# https://leetcode.com/problems/lru-cache/description/

class Node:
    def __init__(self, key, val):
        self.key, self.val = key, val
        self.next = self.prev = None

class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.cap = capacity
        self.cache = {} # key to nodes

        self.left, self.right = Node(0,0), Node(0,0)
        self.left.next, self.right.prev = self.right, self.left
        # left is lru, right is mru

    def remove(self, node): # from left
        prv, nxt = node.prev, node.next
        prv.next = nxt
        nxt.prev = prv
        del node

    def insert(self, node): # from right
        right, prv = self.right, self.right.prev
        prv.next = node
        node.prev = prv

        right.prev = node
        node.next = right 

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key in self.cache:
            self.remove(self.cache[key])
            self.insert(self.cache[key])
            return self.cache[key].val
        return -1
        

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        if key in self.cache:
            self.remove(self.cache[key])
        self.cache[key] = Node(key, value)
        self.insert(self.cache[key])

        if len(self.cache)>self.cap:
            # remove lru
            lru = self.left.next
            self.remove(lru)
            del self.cache[lru.key]


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)