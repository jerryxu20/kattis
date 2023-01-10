import sys

mapping = {'A': 0, 'B': 1, 'C': 2, 'D': 3, 'E': 0, 'F': 1, 'G': 2, 'H': 0, 'I': 0, 'J': 2, 'K': 2, 'L': 4, 'M': 5, 'N': 5, 'O': 0, 'P': 1, 'Q': 2, 'R': 6, 'S': 2, 'T': 3, 'U': 0, 'V': 1, 'W': 0, 'X': 2, 'Y': 0, 'Z': 2}

for line in sys.stdin:
    digits = list(map(lambda x: mapping[x], line[0:-1]))
    ans = []
    if (len(digits) == 0):
        break
    if digits[0] != 0:
        ans.append(digits[0])
    for i in range(1, len(digits)):
        if digits[i] != 0 and digits[i] != digits[i - 1]:
            ans.append(digits[i])
    print(*ans, sep="")
    