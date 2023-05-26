import sys

pieces = [[] for _ in range(2)]
for n, line in enumerate(sys.stdin):
    if n % 2 == 0: continue
    row = n//2
    for i in range(2, len(line.strip()), 4):
        if line[i] in ['.', ':']: continue
        col = i//4
        pieces[int(line[i].islower())].append([line[i].upper(), row, col])

order = {
    'K': -1,
    'Q': 0,
    'R': 1,
    'B': 2,
    'N': 3,
    'P': 4
}

pieces[0].sort(key=lambda x: (order[x[0]], 8-x[1], x[2]))
pieces[1].sort(key=lambda x: (order[x[0]], x[1], x[2]))


white = ",".join([x + chr(ord('a') + j) + str(8 - i) for x, i, j in pieces[0]])
black = ",".join([x + chr(ord('a') + j) + str(8 - i) for x, i, j in pieces[1]])

print("White:", white.replace('P', ''))
print("Black:", black.replace('P', ''))