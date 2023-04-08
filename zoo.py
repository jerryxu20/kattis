import sys
from collections import OrderedDict
t = 1
mp = {}
for line in sys.stdin:
    n = line.strip()
    try:
        n = int(n)
        if (len(mp) > 0):
            for key, cnt in sorted(mp.items()):
                print(key, '|', cnt)
        if (n == 0):
            break
        print(f"List {t}:")
        mp = OrderedDict()
 
        t += 1
        continue
    except:
        pass
    n = n.split()
    n = n[-1].lower()
    if n not in mp:
        mp[n] = 0
    mp[n] += 1
    