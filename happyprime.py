n = int(input())
for _ in range(n):
    a, b = map(int, input().split())
    seen = set()
    def happy(b):
        if b in seen: return False
        if b == 1: return True
        seen.add(b)
        ans = 0
        for digit in str(b):
            ans += int(digit) ** 2
        return happy(ans)
        
    def prime(b):
        if b <= 1: return False
        if b <= 2: return True
        d = 2
        while d * d <= b:
            if b % d == 0: return False
            d += 1
        return True
        
    if happy(b) and prime(b): print(a, b, "YES")
    else: print(a,b, "NO")
