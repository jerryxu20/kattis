from functools import lru_cache

@lru_cache(maxsize=None)
def fact(n):
    if n <= 1: return 1
    return n * fact(n - 1)

def choose(n, k):
    return fact(n) // (fact(k) * fact(n - k))

def solve(nums):
    if len(nums) <= 1: return 1
    root = nums[0]
    left = []
    right = []
    for i in range(1, len(nums)):
        if nums[i] >= root: right.append(nums[i])
        else: left.append(nums[i])
    # print("left", left)
    # print("right", right)
    return choose(len(nums) - 1, len(left)) * solve(left) * solve(right)

while True:
    n = int(input())
    if n == 0: break
    nums = list(map(int, input().split()))
    print(solve(nums))
    