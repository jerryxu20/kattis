import sys
n = int(input())

sm = 0

num = list(map(int, input().split()))
used = [False for _ in range(n)]

for i in range(n):
    if num[i] == 0: continue
    for j in range(i + 1, n):
        if num[i] == 0: break
        if used[j] or num[j] == 0: continue
        used[j] = True
        num[j] -= 1
        num[i] -= 1

    used[i] = True
    if num[i] != 0:
        print("NO")
        sys.exit()
        

if used.count(False) > 0:
    print("NO")
else:
    print("YES")        