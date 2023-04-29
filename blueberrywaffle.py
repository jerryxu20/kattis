r, f = map(int, input().split())
extra = f % r
spins = f // r
if extra * 2 >= r:
    spins += 1
if spins % 2 == 0:
    print("up")
else:
    print("down")
    