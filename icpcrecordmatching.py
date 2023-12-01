import sys

icpc = []
for line in sys.stdin:
    line = line.strip()
    if not line: break
    first, last, email = line.split()
    icpc.append((first, last, email))

outside = []
for line in sys.stdin:
    line = line.strip()
    first, last, email = line.split()
    outside.append((first, last, email))
    
omatch = [0 for _ in range(len(outside))]
imatch = [0 for _ in range(len(icpc))]

def match(a, b):
    if a[2].lower() == b[2].lower(): return True
    return a[0].lower() == b[0].lower() and a[1].lower() == b[1].lower()

for i, a in enumerate(icpc):
    for j, b in enumerate(outside):
        if match(a, b):
            omatch[j] += 1
            imatch[i] += 1

bad = []
for i in range(len(icpc)):
    if imatch[i] > 0: continue
    bad.append(icpc[i])
    
bad2 = []
for i in range(len(omatch)):
    if omatch[i] > 0: continue
    bad2.append(outside[i])

bad.sort(key=lambda x: x[2].lower())
bad2.sort(key=lambda x: x[2].lower())

if not bad and not bad2:
    print("No mismatches.")
    
for a in bad:
    print("I", a[2], a[1], a[0])
    
for a in bad2:
    print("O", a[2], a[1], a[0])