from collections import deque

t = int(input())

for _ in range(t):
    command = input()
    n = int(input())
    nums = []
    if n > 0:
        nums = list(map(int, input()[1:-1].split(',')))
    else:
        input()
    a = deque(nums)
    b = deque(nums[::-1])
    
    error = False
    for c in command:
        if c == 'R':
            a, b = b, a
        elif len(a) == 0:
            error = True
            print("error")
            break
        else:
            a.popleft()
            b.pop()
    if error: continue
    
    nums = [str(x) for x in a]
    print("[" + ",".join(nums) + ']')