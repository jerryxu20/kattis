import sys

facts = []
queries = []

def match(q, f):
    if q[0] != f[0]: return False
    if len(q[1]) != len(f[1]): return False
    defined = {}
    for a, b in zip(q[1], f[1]):
        if a == '_': continue
        if a[0] == '_':
            if a in defined and defined[a] != b:
                return False
            defined[a] = b
            continue
        if a != b: return False
    return True

def clean(s):
    name, rest = s.split('(')
    args = rest.split(',')
    return (name, args)

for line in sys.stdin:
    line = line.strip().replace(' ', '')
    if not line: break
    for chunk in line.split(')')[:-1]:
        facts.append(clean(chunk))
    
for line in sys.stdin:
    line = line.strip().replace(' ', '')
    queries.append(clean(line[:-1]))
    
    
for q in queries:
    ans = 0
    for f in facts:
        if match(q, f):
            ans += 1
    print(ans)