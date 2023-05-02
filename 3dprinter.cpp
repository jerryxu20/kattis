def f(printers, need):
    if printers >= need:
        return 1
    return min(f(2*printers, need), f(printers, need - 1)) + 1
    
n = int(input())
print(f(1, n))