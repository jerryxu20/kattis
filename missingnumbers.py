n = int(input())
nums = [int(input()) for _ in range(n)]
ans = [i for i in range(1, nums[-1] + 1) if i not in nums]
if ans: print(*ans, sep="\n")
else:print("good job")
