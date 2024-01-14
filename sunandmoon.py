import sys
a, b = map(int, input().split())

c, d = map(int, input().split())

st = set()
a = b - a
while a < 10000:
    st.add(a)
    a += b

c = d - c
while c < 10000:
    if c in st:
        print(c)
        sys.exit()
    c += d
    