n = int(input())
notes = [[x[0], int(x[1]) if len(x) > 1 else 1] for x in input().split()]
n = sum(x[1] for x in notes) + len(notes) - 1
labels = ['G', 'F', 'E', 'D', 'C', 'B', 'A', 'g', 'f', 'e', 'd', 'c', 'b', 'a']
dotted = set(['F', 'D', 'B', 'g', 'e', 'a'])
staff = [[' ' for _ in range(n)] for l in range(len(labels))]
i = 0
for a, b in notes:
    for _ in range(b):
        staff[labels.index(a)][i] = '*'
        i += 1
    i += 1

for line, label in zip(staff, labels):
    line = "".join(line)
    if label in dotted:
          line = line.replace(' ', '-')
    print(f"{label}:", line)
   