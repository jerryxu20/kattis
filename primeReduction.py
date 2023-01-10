def numberoffactors(a):
    d = 2
    ans = 0
    while d * d <= a:
        while a % d == 0:
            a //= d
            ans += d
        d += 1
    if a > 1:
        ans += a
    return ans

while True:
    n = int(input())
    if n == 4:
        break
    ans = 1
    while True:
        b = numberoffactors(n)
        if b == n:
            break
        ans += 1
        n = b
    print(n, ans)
    