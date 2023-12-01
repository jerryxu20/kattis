import math
import sys
def push(n):
    return int(n * 100)
def back(n):
    return n/100

tf = push(float(input()))
tr = push(float(input()))

prev = []
for line in sys.stdin:
    num = push(float(line))
    down = num//100 * 100 + tf
    up = num//100 * 100 + tr
    if num == 0:
        print(0)
    elif num < 100:
        print(1)
    elif num <= down:
        print(num//100)
    elif num >= up:
        print(num//100 + 1)
    else:
        for i in range(len(prev) - 1, -1, -1):
            if prev[i] < down:
                print(num//100)
                break
            elif prev[i] > up:
                print(num//100 + 1)
                break
    prev.append(num)
    