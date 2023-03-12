


idd = 0
name = ["" for _ in range(32)]
cast = {}
n = int(input())
adj = [[] for _ in range(n)]
for _ in range(n):
    towns = input().split()
    if towns[0] not in cast:
        cast[towns[0]] = idd
        name[idd] = towns[0]
        idd += 1
    node = cast[towns[0]]
    for i in range(1, len(towns)):
        if towns[i] not in cast:
            cast[towns[i]] = idd
            name[idd] = towns[i]
            idd += 1
        adj[node].append(cast[towns[i]])

start, end = input().split()
start = cast[start]
end = cast[end]
path = []
def dfs(start, end, path):
    path.append(start)
    if (start == end):
        return True
    for nxt in adj[start]:
        if dfs(nxt, end, path):
            return True
    return False

if dfs(start, end, path):
    for p in path:
        print(name[p], end=" ")
else:
    print("no route found")

        