l, r = map(int, input().split())

if l/2 * l/2 + l/2 * l/2 <= r * r:
    print("fits")
else:
    print("nope")