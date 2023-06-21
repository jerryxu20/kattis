while True:
    n = int(input())
    if n == 0: break
    s = input().replace(' ', '').upper()
    grid = ['' for _ in range(n)]
    extra = len(s) % n
    low = 0
    chunk = len(s) // n
    mx = len(s)//n + 1
    for i in range(n):
        high = low + chunk
        if extra > 0:
            high += 1
            extra -= 1
        grid[i] = s[low:high]
        low = high
    ans = []
    for i in range(mx):
        for row in grid:
            if i >= len(row): break
            ans.append(row[i])
    print(*ans, sep="")