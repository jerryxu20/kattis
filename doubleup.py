import collections
n = int(input())

nums = list(map(int, input().split()))


stack = []
for num in nums:
    stack.append(num)
    while len(stack) >= 2:
        if stack[-1] == stack[-2]:
            stack[-2] += stack[-1]
            stack.pop()
            continue
        
        if stack[-1] > stack[-2]:
            stack[-2] = stack[-1]
            stack.pop()
            continue
        break
    
print(max(stack))