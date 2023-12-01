import sys
for line in sys.stdin:
    R, S = map(float, line.split())
    ans = (R * (S + 0.16))/0.067
    print(round(ans ** 0.5))