arr = input().split()
h = int(arr[0]) + 1
if (len(arr) == 1):
    s = ""
else:
    s = arr[1]
    
ans = (1 << h) - 1
idx = 1
for c in s:
    if c == 'L':
        nidx = idx * 2
    else:
        nidx = idx * 2 + 1
    ans -= nidx - idx
    idx = nidx
    
print(ans)
