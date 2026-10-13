class Solution:
	def findRoot(self,representative,x):
		if x==representative[x]:
			return x
		else:
			root = self.findRoot(representative, representative[x])
			representative[x] = root # path compression
			return root

	def accountsMerge(self, accounts: list[list[str]]) -> list[list[str]]:
		## union find
		hashmap={}
		parent = [i for i in range(len(accounts))]
		for i in range(len(accounts)):
			acc = accounts[i]
			for email in acc[1:]:
				if email in hashmap:
					## union
					rep0, rep1 = self.findRoot(parent, i), self.findRoot(parent, hashmap[email])
					if rep0!=rep1:
						parent[rep1] = rep0
				else:
					hashmap[email]=i
		## find all emails for each representative
		ans = {}
		for email in hashmap:
			rep = self.findRoot(parent, hashmap[email])
			if rep not in ans:
				ans[rep]=[]
			ans[rep].append(email)
		## sort emails and add name
		for rep in ans:
			ans[rep].sort()
			ans[rep] = [accounts[rep][0]] + ans[rep]
		return list(ans.values())
