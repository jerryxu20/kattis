import sys
n = int(input())

mp = {
    1: 'I',
    2: 'II',
    3: 'III',
    4: 'IV',
    5: 'V',
    6: 'VI',
    7: 'VII',
    8: 'VIII',
    9: 'IX',
    10: 'X',
    
    20: 'XX',
    30: 'XXX',
    40: 'XL',
    50: 'L',
    60: 'LX',
    70: 'LXX',
    80: 'LXXX',
    90: 'XC',
    100: 'C',
    
    200: 'CC',
    300: 'CCC',
    400: 'CD',
    500: 'D',
    600: 'DC',
    700: 'DCC',
    800: 'DCCC',
    900: 'CM',
    1000: 'M'
}

def translate(n):
    ans = ""
    while n >= 1000:
        n -= 1000
        ans += mp[1000]
    
    while n >= 100:
        x = n//100 * 100
        n -= x
        ans += mp[x]

    while n >= 10:
        x = n//10 * 10
        n -= x
        ans += mp[x]
        
    if n: ans += mp[n]
    return ans

order = {}
arr = [(translate(i), i) for i in range(1, 1001)]
arr.sort()

for i in range(1000):
    s, x = arr[i]
    if s[0] <= 'M':
        order[x] = i + 1
    else:
        order[x] = -(1000 - i)

def search(s, before):
    if not s: return 0
    ans = 0
    if before:
        for i in range(len(arr)):
           if arr[i][0] <= s:
               ans += 1
    else:
        for i in range(len(arr)):
            if arr[i][0] >= s:
                ans -= 1
    return ans 

def dfs(n):
    nom = n % 1000
    before = False
    s = translate(nom)

    if not s or s[0] < 'M':
        before = True

    if n <= 1000:
        return search(translate(n), before)


    x = n//1000

    return search(translate(nom), before) + (search(translate((n % 1000) + 1000), before) * x)

for _ in range(n):
    x = int(input())
    print(dfs(x))
    
