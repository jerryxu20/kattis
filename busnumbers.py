n = int(input())

stops = sorted( list(map(int, input().split())) )

stops.append(10000)

first = stops[0]
brute = str(stops[0])

for i in range(1, len(stops)):
    if stops[i] == stops[i - 1] + 1:
        brute += " " + str(stops[i])
    else:
        short = str(first) + "-" + str(stops[i - 1])
        if len(short) < len(brute):
            print(short, end=" ")
        else:
            print(brute, end=" ")
        brute = str(stops[i])
        first = str(stops[i])

