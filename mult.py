n = int(input())

x = -1
for i in range(n):
    a = int(input())
    if x == -1:
        x = a
        continue
    
    if a % x == 0:
        print(a)
        x = -1