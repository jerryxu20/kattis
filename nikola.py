import sys
n = int(input())
cost = [int(input()) for _ in range(n)]

sys.setrecursionlimit(10**6)
mp = {}
def f(step, jump):
    state = (step, jump)
    if state in mp: return mp[state]
    if step == n - 1: return cost[step]
    ans = 10 ** 6
    if step + jump + 1 < n: ans = min(ans, f(step + jump + 1, jump + 1))
    if step - jump >= 0: ans = min(ans, f(step - jump, jump))
    ans += cost[step]
    mp[state] = ans
    return ans
print(f(1, 1))