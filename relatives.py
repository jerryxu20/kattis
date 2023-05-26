while True:
    n = int(input())
    if n == 0: break
    ans = n
    primes = set()
    d = 2
    while d * d <= n:
        while n % d == 0:
            primes.add(d)
            n //= d
        d += 1
    if n > 1: primes.add(n)
    for p in primes:
        ans -= ans//p
    print(ans)