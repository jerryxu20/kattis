import sys
n = int(input())


ans = 1


for line in sys.stdin:
    a, op, b = line.split(' ')
    a = int(a)
    b = int(b)
    
    if op == '+':
        ans = a + b - ans
    elif op == '-':
        ans = (a-b) * ans
    elif op == '*':
        ans = (a*b) ** 2
    else:
        ans = (a + 1)//2
    
    print(ans)