
def f(n):
    if n >= 1 and n <= 9:
        return n
    res = 1
    while n:
        if n % 10 != 0:
            res *= (n % 10)
        n//=10
    return f(res)

print(f(int(input())))