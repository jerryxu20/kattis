n = int(input())
E = int(input())

heard = [set() for _ in range(n)]
song = 0
for _ in range(E):
    present = list(map(int, input().split()))[1:]
    if 1 in present:
        for i in present:
            heard[i - 1].add(song)
        song += 1
    else:
        st = set()
        st = st.union(*[heard[i - 1] for i in present])
        for i in present:
            heard[i - 1] = st.copy()

print(*[x + 1 for x in range(n) if len(heard[x]) == song], sep="\n")