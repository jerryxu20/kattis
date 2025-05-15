import sys
def id(c):
    if c >= '0' and c <= '9':
        return ord(c) - ord('0')
    if c >= 'a' and c <= 'z':
        return ord(c) - ord('a') + 10
    return ord(c) - ord('A') + 10 + 26

def solve(g):
    coords = [[-1,-1] for _ in range(100)]
    for i, row in enumerate(g):
        for j, c in enumerate(row):
            if c == '.': continue 
            coords[id(c)] = [i, j]
    for i in range(1, len(coords)):
        x, y = coords[i - 1]
        xx, yy = coords[i]
        if y == yy:
            for a in range(min(x, xx), max(x, xx) + 1):
                if grid[a][y] == '.':
                    grid[a][y] = '|'
                elif grid[a][y] == '-':
                    grid[a][y] = '+'
        if x == xx:
            for a in range(min(y, yy), max(y, yy) + 1):
                if grid[x][a] == '.':
                    grid[x][a] = '-'
                elif grid[x][a] == '|':
                    grid[x][a] = '+'
                
    for row in grid:
        print(*row, sep="")

        
    
grid = []
for line in sys.stdin:
    line = line.strip()
    if (len(line) == 0):
        solve(grid)
        grid = []
        continue
    grid.append(list(line))
solve(grid)
