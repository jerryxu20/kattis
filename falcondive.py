n, m, c = input().split()
c = c[1]
n = int(n)
m = int(m)

frame1 = [input() for _ in range(n)]
input()
frame2 = [input() for _ in range(n)]
for i, line in enumerate(frame1):
    j = line.find(c)
    if j != -1: break

for ii, line in enumerate(frame2):
    jj = line.find(c)
    if jj != -1: break
    
dx = jj - j
dy = ii - i

# print(dy, dx)
res = [[a if a != c else b for a, b in zip(l1, l2)] for l1, l2 in zip(frame1, frame2)]
   
for i, line in enumerate(frame2):
    for j, pixel in enumerate(line):
        if pixel == c:
            ii = i + dy
            jj = j + dx
            if ii < 0 or jj < 0 or ii >= n or jj >= m: continue
            res[ii][jj] = c

for line in res:
    print(*line, sep="")