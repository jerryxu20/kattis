import sys


def help(n, k):
    dp = [[0 for _ in range(k)] for i in range(n)]
    for i in range(k):
      dp[0][i] = 1
    for i in range(1, n):
      for j in range(0, k):
        dp[i][j] += dp[i - 1][j]
        if j - 1 >= 0:
          dp[i][j] += dp[i - 1][j - 1]
        if j + 1 < k:
          dp[i][j] += dp[i - 1][j + 1]
    ans = sum(dp[-1])
    return ans


for line in sys.stdin:
    k, n = map(int, line.split())
    if (k <= 1):
      print(100)
      continue
    valid = help(n, k + 1)
    valid *= 100
    total = (k + 1) ** n
    ans = valid / total
    print(f'{ans:.20f}')