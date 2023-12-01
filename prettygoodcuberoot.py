import sys
from math import floor, ceil


def solve(n):
    low = 1
    high = n

    ans = 0
    while low <= high:
        mid = (low + high)//2
        nxt = mid + 1
        
        mid3 = mid ** 3
        nxt3 = nxt ** 3
        
        diff_mid = abs(n - mid3)
        diff_nxt = abs(n - nxt3)
        
        if diff_mid <= diff_nxt:
            high = mid - 1
            ans = mid
        else:
            low = mid + 1
            ans = nxt
    print(ans)
    
for line in sys.stdin:
    solve(int(line))