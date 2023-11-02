# maximum unique substrings that can be extracted from a string while using the entire string exactly once

# sample input : "abccbaabccba"
# sample output : 2

def solve(s, prev, prevsum):
    n = len(s)
    ans = 1
    if(prev == ""):
        if n<=2:
            return n
        for i in range(1,n):
            if (s[i] == s[0] and s[:i]==s[n-i:]):
                    ans = max(ans,solve(s[i:n-i], s[:i], 2))
        return ans
    else:
        if n==0:
            return prevsum
        
        if n<len(prev):
            return 1
        # check for prev in the current string
        if prev == s[:len(prev)]:
            return solve(s[len(prev):], prev, prevsum+1)
        else:
            return 1
        
def solve3(s):
    if(len(s)%2!=0):
        if(s[0]*(len(s))==s):
            return len(s)
        else:
            return 1
    for i in range(1, len(s)):
        if s[:i]*(len(s)//i) == s:
            return len(s)//i
    return 1

def solution2(s):
    return solve(s, "", 0)


def solution(s):
    n = len(s)
    if n <=2:
        return n
    
    for i in range(1, n):
        if s[i] == s[0]:
            if s[:i] == s[n-i:]:
                return 2 + solution(s[i:n-i])
    return 1

if __name__ == "__main__":
    s = input()
    #print(solution2(s))
    print(solve3(s))