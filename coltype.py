s = input()

if s[-1] != 'O' or "OO" in s:
    print("INVALID")
    exit()
    
s = s[::-1]

for i in range(60):
    cur = 1 << i
    valid = 1
    for c in s:
        if c == 'E':
            cur *= 2
            if bin(cur).count('1') == 1:
                valid = 0
        else:
            cur -= 1
            if cur <= 0 or cur % 3 != 0:
                valid = 0
            cur //= 3
            
            if cur % 2 != 1 or cur <= 1:
                valid = 0
    
    if valid:
        print(cur)
        exit(0)
print("INVALID")            
            
            
    
    