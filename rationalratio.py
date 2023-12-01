import math
s, n = input().split()
n = int(n)
tail = float(s)
t = len(s.split('.')[-1])
top = 10 ** (t)
bot = 10 ** (t - n)
x = top - bot
y = int(round(float(s) * top,0)) - int(float(s) * bot)
g = math.gcd(x, y)

y//=g
x//=g
print(f"{y}/{x}")

