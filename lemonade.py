n, m = map(int, input().split())
a, b, c, d, e, f, v = map(int, input().split())
dp = {}

def volume(v, i):
    return ((a * i + b * v) % c) + 1

def lemon(v, i):
    return (d * i + e * v) % f

def solve(turn, cap, vol):
    if turn > m: return 0
    state = (turn, cap, vol)
    if state in dp: return dp[state]
    ans = 0
    # Don't empty this turn
    current_vol = volume(vol, turn)
    ans = solve(turn + 1, cap, current_vol)
    
    # Empty this turn
    if cap >= current_vol:
        ans = max(ans, lemon(vol, turn) + solve(turn + 1, cap - current_vol, 0))
    dp[state] = ans
    return ans
    
print(solve(1, n, v))
    