## https://leetcode.com/problems/find-closest-node-to-given-two-nodes/

class Solution:
	def closestMeetingNode(self, edges: list[int], node1: int, node2: int) -> int:
		n = len(edges)
		seen1 = [False] * n
		seen2 = [False] * n
		a, b = node1, node2

		while a != -1 or b != -1:
			if a != -1:
				seen1[a] = True
			if b != -1:
				seen2[b] = True

			candidates = []
			if a != -1 and seen2[a]:
				candidates.append(a)
			if b != -1 and seen1[b]:
				candidates.append(b)
			if candidates:
				return min(candidates)
			if a != -1:
				a = edges[a]
				if a != -1 and seen1[a]:
					a = -1
			if b != -1:
				b = edges[b]
				if b != -1 and seen2[b]:
					b = -1

		return -1
