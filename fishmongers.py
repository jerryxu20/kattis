n, m = map(int, input().split())
fish = list(map(int, input().split()))
mongers = [list(map(int, input().split())) for _ in range(m)]
mongers.sort(key=lambda x: x[1], reverse=True)
fish.sort(reverse=True)

i = 0
ans = 0
for f in fish:
    while i < len(mongers) and mongers[i][0] == 0:
        i += 1
    if i < len(mongers):
        mongers[i][0] -= 1
        ans += mongers[i][1] * f
        
print(ans)
