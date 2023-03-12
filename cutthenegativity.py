m = int(input())
flights = []
for i in range(1, m + 1):
    row = list(map(int, input().split()))
    for idx, cost in zip(range(1, m + 1), row):
        if cost < 0:
            continue
        flights.append([i, idx, cost])
flights.sort()
print(len(flights))
for flight in flights:
    print(*flight)

