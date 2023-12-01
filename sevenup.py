s = input()
s = s.replace('A', '1')

cnt = [4 - s.count(chr(i + ord('0'))) for i in range(1, 8)]
bad = 45 - sum(cnt)

mp = {}
def f(bitmask, cnt, bad):
    state = (bitmask, *cnt, bad)
    if state in mp: return mp[state]
    ans = 1
    total = sum(cnt) + bad
    if bitmask == ((1 << 7) - 1): return 0
    for i in range(7):
        if cnt[i] == 0: continue
        if (bitmask & (1 << i)) == 0:
            top = i
            nbitmask = bitmask
            while True:
                nbitmask |= (1 << top)
                # the card I'm swapping with is bad
                if s[top] < '1' or s[top] > '7': break
                top = ord(s[top]) - ord('1')
                # the card I'm swapping with is already face up
                if (nbitmask & (1 << top)) != 0: break
            cnt[i] -= 1
            ans += (cnt[i] + 1)/total * f(nbitmask, cnt, bad)
            cnt[i] += 1
        else:
            cnt[i] -= 1
            ans += (cnt[i] + 1)/total * f(bitmask, cnt, bad)
            cnt[i] += 1

    if bad > 0:
        ans += (bad/total) * f(bitmask, cnt, bad - 1)
    mp[state] = ans
    return ans
print(f(0, cnt, bad))