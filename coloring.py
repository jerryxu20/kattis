n = int(input())
adj = [list(map(int, input().split())) for _ in range(n)]
low = 2
high = n
ans = 2
while low <= high:
    mid = (low + high) // 2
    color = [-1 for _ in range(n)]
    color[0] = 0
    color[adj[0][0]] = 1
    
    def colorable(i, m):
        if i == n: return True
        if color[i] != -1: return colorable(i + 1, m)
        bad = set([color[x] for x in adj[i]])
        for c in range(m):
            if c in bad: continue
            color[i] = c
            if colorable(i + 1, m): return True
        color[i] = -1
        return False
    
    if colorable(0, mid):
        high = mid - 1
        ans = mid
    else:
        low = mid + 1

print(ans)