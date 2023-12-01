n, m, q = map(int, input().split())
att = [input() for _ in range(n)]

st = set(range(n))
for _ in range(q):
    a, s = input().split()
    a = int(a) - 1
    new_st = set()
    for p in st:
        if att[p][a] == s:
            new_st.add(p)
    st = new_st
    
assert len(st) >= 1

if len(st) > 1:
    print("ambiguous")
    print(len(st))
else:
    print("unique")
    for s in st:
        print(s + 1)
    