a, b, c = map(int, input().split())

def plus(a, b):
    return a + b
def minus(a, b):
    return a - b
def times(a, b):
    return a * b
def div(a, b):
    assert a % b == 0
    return a // b

op = [plus, minus, times, div]
ans = a + b + c

for f1 in op:
    for f2 in op:
        try:
            cand = f2(f1(a, b), c)
            if cand < 0: continue
            ans = min(ans, cand)
        except:
            pass
print(ans)