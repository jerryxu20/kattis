import sys
nums = [['xxxxx', 'x...x', 'x...x', 'x...x', 'x...x', 'x...x', 'xxxxx'], ['....x', '....x', '....x', '....x', '....x', '....x', '....x'], ['xxxxx', '....x', '....x', 'xxxxx', 'x....', 'x....', 'xxxxx'], ['xxxxx', '....x', '....x', 'xxxxx', '....x', '....x', 'xxxxx'], ['x...x', 'x...x', 'x...x', 'xxxxx', '....x', '....x', '....x'], ['xxxxx', 'x....', 'x....', 'xxxxx', '....x', '....x', 'xxxxx'], ['xxxxx', 'x....', 'x....', 'xxxxx', 'x...x', 'x...x', 'xxxxx'], ['xxxxx', '....x', '....x', '....x', '....x', '....x', '....x'], ['xxxxx', 'x...x', 'x...x', 'xxxxx', 'x...x', 'x...x', 'xxxxx'], ['xxxxx', 'x...x', 'x...x', 'xxxxx', '....x', '....x', 'xxxxx'], ['.....', '..x..', '..x..', 'xxxxx', '..x..', '..x..', '.....']]
lines = [x.strip() for x in sys.stdin]
n = len(lines[0])
digits = [[] for _ in range((n + 1)//6)]
for line, idx in zip(lines, range(100000)):
    for i in range(0, n, 6):
        digits[i // 6].append(line[i:i+5])

num = ""
ans = 0

# for digit in digits:
#     for row in digits:
#         print(*row)
        
#     print()

for digit in digits:
    idx = nums.index(digit)
    if idx == 10:
        ans += int(num)
        num = ""
        continue
    num += str(idx)

ans += int(num)
for i in range(7):
    for c, j in zip(str(ans), range(1, 10000)):
        idx = ord(c) - ord('0')
        print(nums[idx][i], end="")
        if j != len(str(ans)):
            print(".", end="")
    print()