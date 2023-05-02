low = 0
high = 10
E = 1e-8
n = int(input())
while (high - low > E):
    mid = (low + high) / 2
    if mid ** mid > n:
        high = mid
    else:
        low = mid
print(low)