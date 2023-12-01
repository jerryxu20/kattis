n, m, d = map(int, input().split())


mine = list(map(int, input().split()))
enemy = list(map(int, input().split()))

mine = [mine.count(x) for x in range(1, 7)]
enemy = [enemy.count(x) for x in range(1, 7)]
dp = {}

def f(a, b, n):
    A = sum(a)
    B = sum(b)
    
    if B == 0: return 1

    total = A + B
    if n == 0: return 0    

    state = (*a, *b)
    if state in dp:
        return dp[state]

    ans = 0
    for i in range(6):
        if a[i] == 0: continue
        dudes = a[i]
        a[i] -= 1
        if i - 1 >= 0:
            a[i - 1] += 1
            
        ans += dudes/total * f(a, b, n - 1)
        a[i] += 1
        if i - 1 >= 0:
            a[i - 1] -=  1
        
    for i in range(6):
        if b[i] == 0: continue
        dudes = b[i]
        b[i] -= 1
        if i - 1 >= 0:
            b[i - 1] += 1
            
        ans += dudes/total * f(a, b, n - 1)
        b[i] += 1
        if i - 1 >= 0:
            b[i - 1] -=  1
    dp[state] = ans
    return ans

print(f(mine, enemy, d))