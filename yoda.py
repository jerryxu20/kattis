a = input()
b = input()
cap = max(len(a), len(b))
a = '0' * cap + a
b = '0' * cap + b
a = a[-cap:]
b = b[-cap:]

aa = ""
bb = ""
for x, y in zip(a, b):
    if x == y:
        aa += x
        bb += y
    elif x > y:
        aa += x
    else:
        bb += y

print(int(aa) if aa else "Yoda")
print(int(bb) if bb else "Yoda")