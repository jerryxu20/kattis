import math
n = int(input())

for _ in range(n):
    b, p = map(float, input().split())
    tmin = p / (b + 1)
    tmax = p / (b - 1)
    print(60 / tmax, b / (p / 60), 60 / tmin)
    