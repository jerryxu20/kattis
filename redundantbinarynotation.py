import sys
sys.setrecursionlimit(int(1e6))
n, t = map(int, input().split())
dp = {}
MOD = 998244353
def f(i, n):
    if n == 0: return 1

    if n < 0: return 0
    if i < 0: return 0

    mx = t * (1 << (i + 1))
    if n > mx: return 0
    state = (i, n)
    
    if state in dp:
        return dp[state]

    ans = 0
    for digit in range(t + 1):
        val = digit * (1 << i)
        ans += f(i - 1, n - val)
        ans %= MOD
    dp[state] = ans
    return ans        
        
print(f(55, n))