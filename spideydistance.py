import math
n, m = map(int, input().split())

def spidey(r, n):
    # for each (l, r) pair we save 0.5 units
    # binary search the max ls we can have
    ans = 0
    low = 0
    high = 10 ** 6
    while low <= high:
        mid = (low + high)//2
        pairs = min(mid, r)
        cost = r + mid - min(mid, r)//2
        if cost > n:
            high = mid - 1
        else:
            ans = mid
            low = mid + 1
    return ans

def taxi(r, n):
    # 1, 2, .. n - r works
    if r > n: return 0
    return n - r

def solve(n, m):
    # total area covered by spidey(m)
    total = 0
    
    # total area covered by both taxi(n) and spidey(m)
    both = 0
    
    # Consider only first quadrant and points not on the axis
    # Each point can be represented uniquely by a number of right moves and left moves
    # For each number of right moves 1, 2, 3, ... n - 1
    # Calculate the number of left moves (1, 2, .. x) that we can use 
    # x depends on the number right moves and whether we are using spidey or not
    for i in range(1, m + 1):
        a = spidey(i, m)
        b = taxi(i, n)
        
        both += min(a, b)
        total += a
    
    total *= 4
    both *= 4
    # Count the axis
    total += 4*m
    both += 4*min(n,m)
    return (both + 1, total + 1)

a, b = solve(n, m)
g = math.gcd(a, b)

a //= g
b //= g

if b == 1:
    print(1)
else:
    print(f"{a}/{b}")