n = int(input())

def solve(a):
    if a == 1: return 1
    if a == 2: return 3
    if a == 3: return 5
    if a == 4: return 9

    x = bin(a)[2:]
    if x.count('1') == 1:
        return 3 * solve(a//2)
    
    largest2 = int('1' + '0' * (len(x) - 1), 2)
    return solve(largest2) + 2 * solve(a - largest2)
    
print(solve(n))