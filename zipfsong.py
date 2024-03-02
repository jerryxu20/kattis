import math
class Frac:
    def __init__(self, top, bot):
        self.top = top
        self.bot = bot
        if self.top == 0:
            self.bot == 1
            return 
        
        assert self.bot != 0
        g = math.gcd(top, bot)
        self.top //= g
        self.bot //= g
        return 


    def __mul__ (self, rhs):
        t = rhs.top * self.top
        b = rhs.bot * self.bot
        
        return Frac(t, b)
    
    def __truediv__ (self, rhs):
        rhs = Frac(rhs.bot, rhs.top)
        return self * rhs
    

    
    def __eq__ (self, rhs):
        return self.top == rhs.top and self.bot == rhs.bot
    
    # def __gt__ (self, rhs):
    #     a = self.top * rhs.top
    #     b = rhs.top * self.top
    #     return a > b

    def __lt__(self, rhs):
        a = self.top * rhs.bot
        b = rhs.top * self.bot
        return a > b
    


n, m = map(int, input().split())

cnt = []
name = []

for _ in range(n):
    a, b = input().split()
    cnt.append(int(a))
    name.append(b)
    

sm = sum(cnt)

items = []
# print(cnt)
for i in range(n):
    ratio = Frac(cnt[i] * (i + 1), sm)
    items.append((ratio, i))
    
items.sort()

# for x, _ in items:
#     print(x.top/x.bot)

for i in range(m):
    print(name[items[i][1]])