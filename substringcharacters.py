import sys
for s in sys.stdin:
    s = s.strip()
    p = set(s)
    
    seen = set()
    ans = 0
    for l in range(1, len(s)):
        for i in range(len(s)):
            if i + l > len(s): break
            sub = s[i:i+l]
            if sub in seen: continue
            seen.add(sub)
            a = set(sub)
            if l == 1:
                if len(a) == len(p): ans += 1
                continue
            b = set(sub[1:])
            c = set(sub[:-1])
            if len(a) != len(p) or len(a) == len(b) or len(a) == len(c):
                continue
            ans += 1
    print(ans)
            
                