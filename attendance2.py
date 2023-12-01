N = int(input())

s = [input() for _ in range(N)]

present = set()

for i in range(1, N):
    if s[i] == 'Present!':
        present.add(s[i - 1])
        
absent = []

for c in s:
    if c == 'Present!' or c in present: continue
    absent.append(c)
    
if (len(absent) == 0): print("No Absences")
else:
    for c in absent:
        print(c)