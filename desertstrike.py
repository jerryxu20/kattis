MOD = 10 ** 9 + 9

k, w = map(int, input().split())

# draw a line with length ceil(k/2), draw a line up, draw a line with floor(k/2)
# target is (w, floor(w * 2/k))

h = (w * 2)//k
x = [0, w, w - h, -h]
y = [0, h, h + w,  w]

short = k//2
long = (k + 1)//2
n = min(w//(short + long),h//2)
w -= (short + long) * n
ans = 0

# each one is a series
if n > 0:
    # for long it's long * (0, 2, 4, 6, ...) -> long * 2 * (0, 1, 2, 3 ...)
    # for short it's short * (1, 3, 5, 7, ...) -> short * n + short * (0, 2, 4, 6, ...)
    ans += long * 2 * (n * (n - 1))//2
    ans += short * n + short * 2 * (n * (n - 1))//2


height = max(0, 2*n)

if w >= long:
    ans += long * height
    w -= long 
    height += 1

if w > 0:
    assert height == h
    ans += w * height
    
sub = 4 * ans
area = (max(x) - min(x)) * (max(y) - min(y))
print((area - sub) % MOD)

