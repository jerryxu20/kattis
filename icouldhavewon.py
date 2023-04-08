s = input()
ans = []
for i in range(1, 2001):
    a = 0
    b = 0
    aa = 0
    bb = 0
    for c in s:
        if c == 'A':
            a += 1
        else:
            b += 1
        if a == i:
            aa += 1
        if b == i:
            bb += 1
        if a == i or b == i:
            a = 0
            b = 0
    if aa > bb:
        ans.append(i)
        
print(len(ans))
print(*ans)