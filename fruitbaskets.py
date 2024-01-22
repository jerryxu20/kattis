n = int(input())

fruit = list(map(int, input().split()))

ans = 0

# calc answer assuming all sets are good
# each fruit contributes to 2 ** (n - 1) sets
for f in fruit:
    ans += f * (2 ** (n - 1))

# remove sets of size 1, 2, 3 that are bad
for i in range(n):
    if fruit[i] < 200: ans -= fruit[i]
    for j in range(i + 1, n):
        if fruit[i] + fruit[j] < 200: ans -= fruit[i] + fruit[j]
        for k in range(j + 1, n):
            if fruit[i] + fruit[j] + fruit[k] < 200: ans -= fruit[i] + fruit[j] + fruit[k]
print(ans)