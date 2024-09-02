n = int(input())

said = set()

prev = ""
for i in range(n):
    s = input()
    if prev and s[0] != prev or s in said:
        print("Player", (i % 2) + 1, "lost")
        exit()
    said.add(s)
    prev = s[-1]
print("Fair game")