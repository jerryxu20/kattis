
n, m = map(int, input().split())
times = [list(map(int, input().split())) for _ in range(n)]


dp = {}
dp[(0, 0)] = times[0][0]

def f(i, m):
    state = (i, m)
    if state in dp:
        return dp[state]
    ans = 0
    if i > 0:
        ans = max(ans, f(i - 1, m))
    if m > 0:
        ans = max(ans, f(i, m - 1))
    ans += times[i][m]
    dp[state] = ans

    return ans

for i in range(n):
    print(f(i, m - 1), end=" ")