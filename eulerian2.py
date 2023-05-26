import collections
import sys
n, m = map(int, input().split())
edges = collections.defaultdict(int)
for _ in range(m):
    a, b = map(int, input().split())
    edges[(a,b)] += 1

w = input()

path = list(map(int, input().split()))
for i in range(1, len(path)):
    edge = (path[i - 1], path[i])
    if edges[edge] == 0:
        print(i)
        sys.exit()
    edges[edge] -= 1

for a, b in edges.items():
    if b != 0:
        print("too short")
        sys.exit()
print("correct")