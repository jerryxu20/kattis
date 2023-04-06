# // 4
# // T F T F
# // A B * C D + - +

n = int(input())
vals = list(map(lambda x: x == 'T', input().split()))
cir = input().replace(' ', '')
chunks = []
for c in cir:
    if c.isalpha():
        b = ord(c) - ord('A')
        chunks.append(vals[b])
        continue
    if c == '-':
        chunks[-1] = not chunks[-1]
        continue
    a = chunks[-1]
    b = chunks[-2]
    chunks.pop()
    chunks.pop()
    if c == '*':
        chunks.append(a and b)
    if c == '+':
        chunks.append(a or b)

print(str(chunks[-1])[0])    
        