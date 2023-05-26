import sys
for line in sys.stdin:
    a, b = map(int, line.split())
    if b == 0:
        print(b, "does not divide", f"{a}!")
        continue
    if b == 1:
        print(b, "divides", f"{a}!")
        continue
    if a <= 1:
        print(b, "does not divide", f"{a}!")
        continue
    f = []
    def factor(n):
        div = 2
        while div * div <= n:
            while n % div == 0:
                f.append(div)
                n //= div
            div += 1
        if n > 1: f.append(n)
    factor(b)
    allowed = {}
    bad = False
    for fact in f:
        if bad: break
        for num in range(fact, 100000000000000000, fact):
            if num > a:
                bad = True
                break
            if num not in allowed or allowed[num] > 0:
                allowed[num] = allowed.get(num, 1) - 1
                allowed[num//fact] = allowed.get(num//fact, 1) + 1
                break
    if bad: print(b, "does not divide", f"{a}!")
    else: print(b, "divides", f"{a}!")
