n = int(input())
p = 1
ans = 1
while n > p:
    p *= 2
    ans += 1
print(ans)