import sys
sys.setrecursionlimit(10000000)

n = int(input())

def f(x, y, consts, c, d, memo):
    if ((x, y) in memo):
        return memo[(x, y)]
    if x <= 0 or y <= 0:
        return d
    memo[(x, y)] = c
    for i in range(0, len(consts), 2):
        memo[(x, y)]  += f(x - consts[i], y - consts[i + 1], consts, c, d, memo)
    return memo[(x, y)] 

for _ in range(n):
    consts = list(map(int, input().split()))
    c, d = consts[-2], consts[-1]
    consts = consts[:-2]
    pairs = list(map(int, input().split()))
    memo = {}
    for i in range(0, len(pairs), 2):
        x = pairs[i]
        y = pairs[i + 1]
        print(f(x, y, consts, c, d, memo))
    print()
    
