q, n, d = map(int, input().split())

# q is number of chars
# d is distance

s1 = list(map(int, input()))
s2 = list(map(int, input()))
dp = {}
def f(i, target):
    if i == n: return int(target == 0)
    
    state = (i, target)

    if state in dp:
        return dp[state]
    
    ans = 0
    for c in range(q):
        # consider using char q
        delta = int(s1[i] != c) + int(s2[i] != c)
        ans += f(i + 1, target - delta)
    
    dp[state] = ans
    return ans

print(f(0, d))