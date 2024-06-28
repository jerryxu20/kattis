import sys
files = set()
for s in sys.stdin:
    s = s.strip()
    if len(s) == 0: break
    files.add(s)
    
index = set()
F = []
for s in sys.stdin:
    s = s.strip()
    name = s.rsplit('_', 2)[0]
    if name not in files:
        F.append(s)
    index.add(name)
I = []
for file in files:
    if file not in index:
        I.append(file)
F.sort()
I.sort()

for x in F:
    print("F", x)
for x in I:
    print("I", x)
if len(F) == 0 and len(I) == 0:
    print("No mismatches.")