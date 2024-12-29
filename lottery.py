import math
m, n, t, p = map(int, input().split())
r = m - p

res = 0

def choose(n, k):
    assert k >= 0 and n >= k
    return math.factorial(n)//math.factorial(k)//math.factorial(n - k)

for i in range(1, p + 1):
    if i > n: break
    if i + r < n or i * t < p:
        continue    
    
    ans = choose(p, i)/choose(m, n) * choose(r, n - i)
    res += ans
print(f"{res:.20f}")