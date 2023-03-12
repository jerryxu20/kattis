import sys
for line in sys.stdin:
    possible = []
    inp = line.split("0x")
    for i in inp:
        t = i.split("0X")
        possible += t
    print(possible)