n = int(input())
closest = n
last = {}

for i in range(n):
    s = input()
    if s in last:
        closest = min(closest, i - last[s])
    last[s] = i
    
print(n - closest)

