c, n = map(int, input().split())

err = list(map(int, input().split()))
good = []

st = set(err)
for i in range(1, c + 1):
    if i not in st:
        good.append(i)

def pull(arr):
    a = []
    low = arr[0]
    high = arr[0]
    for e in arr:
        if e > high + 1:
            a.append((low, high))
            low = e
            high = e
        else:
            high = e    
    a.append((low, high))
    return a

a = pull(err)
b = pull(good)

def pprint(arr):
    for i in range(len(arr)):
        if len(arr) > 1 and i == len(arr) - 1:
            print(" and", end="")
            
        if i > 0 and i != len(arr) - 1:
            print(",", end="")
            
        if arr[i][0] == arr[i][1]:
            print("", arr[i][0], end="")
        else:
            print("",f"{arr[i][0]}-{arr[i][1]}", end="")
    print()

print("Errors:", end="")
pprint(a)
print("Correct:", end="")
pprint(b)