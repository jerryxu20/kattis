from cmath import asin
import math
while True:
    r, h, s = map(int, input().split())
    if (r + h + s == 0):
        break
    factor = 1.0 + s / 100.0
    theta =  math.pi / 2.0 - math.asin(r / h)
    theta *= 2
    p = r * (2 * math.pi - theta)
    t = 2 * math.sqrt(h * h - r * r)
    ans = p + t
    ans *= factor
    ans = round(ans, 2)
    print( '{:.2f}'.format(ans))