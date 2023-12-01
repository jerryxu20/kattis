import math
l, d, n = map(int, input().split())

def calc(a, b):
    if a > b: return 0
    return (b - a)//d + 1

sat = sorted([int(input()) for _ in range(n)])
ans = 0
for i in range(1, n):
    ans += calc(sat[i - 1] + d, sat[i] - d)
    
if n > 0:
    ans += calc(6, sat[0] - d)
    ans += calc(sat[-1] + d, l - 6)
else:
   ans += calc(6, l - 6)
print(ans)