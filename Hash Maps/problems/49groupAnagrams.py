# https://leetcode.com/problems/group-anagrams/description/?envType=problem-list-v2&envId=hash-table

import collections

class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        hash_map = collections.defaultdict(list)
        for s in strs:
            count = [0]*26 # create a list of 26 zeros
            for c in s:
                count[ord(c)-ord('a')]+=1

            hash_map[tuple(count)].append(s) # lists are not hashable, so convert to tuple

        return hash_map.values()