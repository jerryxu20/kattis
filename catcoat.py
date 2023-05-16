import collections
cats = {
    "Black": "B-D-o",
    "Blue": "B-ddo",
    "Chocolate": "bbD-o",
    "Lilac": "bbddo",
    "Red": "D-O",
    "Cream": "ddO",
    "Black-Red Tortie": "B-D-Oo",
    "Blue-Cream Tortie": "B-ddOo",
    "Chocolate-Red Tortie": "bbD-Oo",
    "Lilac-Cream Tortie": "bbddOo",
}
female = cats[input()]
male = cats[input()]

if 'o' in female and 'O' not in female:
    female += 'o'


if 'O' in female and 'o' not in female:
    female += 'O'

fodds = collections.defaultdict(int)
modds = collections.defaultdict(int)
for i, gene in enumerate(female):
    if gene != '-':
        fodds[gene] += 1/2
    else:
        fodds[female[i - 1].upper()] += 1/4
        fodds[female[i - 1].lower()] += 1/4
           
    
for i, gene in enumerate(male):
    if gene != '-':
        modds[gene] += 1/2
    else:
        modds[male[i - 1].upper()] += 1/4
        modds[male[i - 1].lower()] += 1/4

            
            
if modds['B'] == 0 and modds['b'] == 0:
    modds['B'] = 1/2
    modds['b'] = 1/2

if fodds['B'] == 0 and fodds['b'] == 0:
    fodds['B'] = 1/2
    fodds['b'] = 1/2
   
fodds['-'] = 1
modds['-'] = 1
ans = []
for cat, pattern in cats.items():
    isfemale = pattern.count('o') + pattern.count('O') == 2
    odds = 1
    for i in range(0, len(pattern)-1, 2):
        a, b = pattern[i:i+2]
        if a == b:
            c = fodds[a] * modds[b]
        else:
            c = (fodds[a] * modds[b] + modds[a] * fodds[b])
        if b == '-':
            c -= fodds[a] * modds[a]
        odds *= c
    if len(pattern) % 2 == 1:
        odds *= (fodds[pattern[-1]] * 1/2 + fodds[pattern[-1]] * modds[pattern[-1]])
    if odds > 0:
        ans.append((cat, odds))
        
ans.sort(key=lambda x: (-x[1], x[0]))
for a in ans:
    print(*a)