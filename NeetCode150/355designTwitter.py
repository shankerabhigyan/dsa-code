


from collections import defaultdict
import heapq

class Twitter(object):

    def __init__(self):
        self.users = {}
        self.cnt = 0
        self.tweetmap = defaultdict(list)
        self.followmap = defaultdict(set)

    def postTweet(self, userId, tweetId):
        """
        :type userId: int
        :type tweetId: int
        :rtype: None
        """
        self.tweetmap[userId].append([self.cnt,tweetId])
        self.cnt-=1

    def getNewsFeed(self, userId):
        """
        :type userId: int
        :rtype: List[int]
        """
        res = []
        heap = []
        self.followmap[userId].add(userId)
        for followeeId in self.followmap[userId]:
            if followeeId in self.tweetmap:
                index = len(self.tweetmap[followeeId])-1
                count, tweetid = self.tweetmap[followeeId][index]
                heap.append([count,tweetid,followeeId, index-1])
        heapq.heapify(heap)

        while heap and len(res)<10:
            count,tweetid,followeeId, index = heapq.heappop(heap)
            res.append(tweetid)
            if index>=0:
                count, tweetid = self.tweetmap[followeeId][index]
                heapq.heappush(heap,[count,tweetid,followeeId, index-1])

        return res

        

    def follow(self, followerId, followeeId):
        """
        :type followerId: int
        :type followeeId: int
        :rtype: None
        """
        self.followmap[followerId].add(followeeId)
        

    def unfollow(self, followerId, followeeId):
        """
        :type followerId: int
        :type followeeId: int
        :rtype: None
        """
        if followeeId in self.followmap[followerId]:
            self.followmap[followerId].remove(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)