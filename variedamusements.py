n, a, b, c = map(int, input().split())
MOD = int(1e9) + 7

dp = {}
def f(n, last):
    if n == 0: return 1
    
    state = (n, last)
    if state in dp:
        return dp[state]

    ans = 0
    
    if a > 0 and last != 1:
        ans += a * f(n - 1, 1)

    if b > 0 and last != 2:
        ans += b * f(n - 1, 2)
        
    if c > 0 and last != 3:
        ans += c * f(n - 1, 3)    

    ans %= MOD
    dp[state] = ans
    return ans

print(f(n, -1))
