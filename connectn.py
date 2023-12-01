n, m, k = map(int, input().split())

grid = [input().replace(' ', '') for _ in range(n)]
grid2 = ["".join([grid[i][j] for i in range(n)]) for j in range(m)]
diag = []

def dfs(i, j, di, dj):
    if i < 0 or i >= n or j < 0 or j >= m: return ""
    ans = grid[i][j]
    ans += dfs(i + di, j + dj, di, dj)
    return ans

for i in range(n):
    diag.append(dfs(i, 0, -1, 1))
    diag.append(dfs(i, 0, 1, 1))
    diag.append(dfs(i, m - 1, -1, -1))
    diag.append(dfs(i, m - 1, 1, -1))

for j in range(m):
    diag.append(dfs(n - 1, j, 1, -1))
    diag.append(dfs(n - 1, j, 1, 1))
    diag.append(dfs(0, j, -1, 1))
    diag.append(dfs(0, j, -1, -1))
    
def win(s, c):
    return c * k in s

def check(c):
    for row in grid:
        if win(row, c): return True
    for row in grid2: 
        if win(row, c): return True
    for row in diag:
        if win(row, c): return True
    return False    
    
    
if check('B'): print("BLUE WINS")
elif check('R'): print("RED WINS")
else: print("NONE")