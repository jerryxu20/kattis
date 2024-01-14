n, k = map(int, input().split())

prev = 0
ans = 0
for i in range(1, n + 1):
    l = len(str(i))
    prev *= 10 ** l
    prev += i
    prev %= k
    if prev == 0:
        ans += 1

print(ans)