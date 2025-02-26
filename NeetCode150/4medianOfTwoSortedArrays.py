# https://leetcode.com/problems/median-of-two-sorted-arrays/description/

# BINARY SEARCH

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        a,b = nums1, nums2

        if len(a)<len(b):
            a,b = b,a

        total = len(a)+len(b)
        l,r = 0,len(a)-1
        m1,m2 = 0,0
        while True:
            m1 = (l+r)//2
            m2 = ((total//2)-m1) - 2 # boundary of the left partition in the second array

            aleft = a[m1] if m1>=0 else float("-infinty")
            aright = a[m1+1] if (m1+1)<len(a) else float("infinity")
            bleft = b[m2] if m2>=0 else float("-infinity")
            bright = b[m2+1] if (m2+1)<len(b) else float("infinity")

            if aleft>bright:
                r = m1-1
            if bleft>aright:
                l = m1+1
            else:
                if total%2==1:
                    return min(aright,bright)
                else:
                    return (max(aleft,bleft)+min(aright,bright))/2.0
        