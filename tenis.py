a, b = input().split()

N = int(input())
for _ in range(N):
    games = input().split()
    good = True
    A = 0
    B = 0
    for i, g in enumerate(games):
        x, y = map(int, g.split(':'))
        if x == y:
            good = False
            break
        if A == 2 or B == 2:
            good = False
            break
        if x < y and a == "federer":
            good = False
            break
        if y < x and b == "federer":
            good = False
            break
        mn, mx = min(x,y), max(x, y)
        if mx < 6:
            good = False
            break
        
        # Normal win that can always happen
        if mx == 6 and mn <= 4:
            if x > y: A += 1
            else: B += 1
            continue
        
        # Wrong in first two games
        if i < 2 and mn > 6:
            good = False
            break
        
        # Overtime win and bad delta

        if i < 2 and mn == 6 and mx != 7:
            good = False
            break 
    
        if i < 2 and mx == 7 and mn == 6:
            if x > y: A += 1
            else: B += 1
            continue
    

        if mx - mn != 2:
            good = False
            break
        
        if x > y: A += 1
        else: B += 1
        
    if A == B:
        good = False
    if max(A, B) != 2:
        good = False  
    if good:
        print("da")
    else:
        print("ne")
        
