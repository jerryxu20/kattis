a, b = map(int, input().split())

dp = {}
def f(n):
    if n < 7: return 0
    if n <= 16: return 1
    if n in dp: return dp[n]
    
    s = str(n)
    end = int(s[1:])
    start = int(s[0])

    dp[n] = f(n - end - 1)
    if start == 7:
        dp[n] += (end + 1)
    else:
        dp[n] += f(end) 
    return dp[n]

print(f(b) - f(a - 1))
