# https://leetcode.com/problems/time-based-key-value-store/description/

# BINARY SEARCH

import collections

class TimeMap(object):

    def __init__(self):
        self.hashmap = {}

    def set(self, key, value, timestamp):
        """
        :type key: str
        :type value: str
        :type timestamp: int
        :rtype: None
        """
        if key not in self.hashmap:
            self.hashmap[key] = []
        self.hashmap[key].append((timestamp,value))
        

    def get(self, key, timestamp):
        """
        :type key: str
        :type timestamp: int
        :rtype: str
        """
        if key not in self.hashmap:
            return ""

        values = self.hashmap[key]
        l, r = 0, len(values)-1

        result = ""
        while l<=r:
            mid = l + (r-l)//2
            if values[mid][0]<=timestamp:
                result = values[mid][1]
                l = mid+1
            else:
                r = mid-1

        return result