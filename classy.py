t = int(input())

mp = {
    "middle": 1,
    "lower": 2,
    "upper": 0,
}

for _ in range(t):
    n = int(input())
    
    dudes = []
    for i in range(n):
        name, c = input().split(": ")
        carr = c.split()[0].split('-')
        carr = carr[::-1]

        ranking = [mp[x] for x in carr]
        while len(ranking) < 10:
            ranking.append(1)
        dudes.append((ranking, name))
    
    dudes.sort()    
    for _, x in dudes:
        print(x)
    
    print("==============================")