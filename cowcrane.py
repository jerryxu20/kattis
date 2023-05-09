a, b = map(int, input().split())
A, B = map(int, input().split())
TA, TB = map(int, input().split())

distance = {}
def f(x, a, b, t, cow1, cow2):
    state = (x, a, b, cow1, cow2)
    if state in distance and t > distance[state]: return False
    distance[state] = t
    # It's over
    if not cow1 and t > TA: return False
    if not cow2 and t > TB: return False 
    if cow1 and cow2: return True
    
    # We are at a temp location
    if x == a and x == A and not cow1:
        return f(a, a, b, t, True, cow2)
    if x == b and x == B and not cow2:
        return f(b, a, b, t, cow1, True)

    locations = [a, b]
    if not cow1: locations.append(A)
    if not cow2: locations.append(B)

    # Move cows somewhere new
    if x == a and not cow1:
        for L in locations:
            if L == x: continue
            if f(L, L, b, t + abs(x - L), cow1, cow2): return True
            
    if x == b and not cow2:
        for L in locations:
            if L == x: continue
            if f(L, a, L, t + abs(x - L), cow1, cow2): return True

    # Go to each cow
    if not cow1 and x != a and f(a, a, b, t + abs(x-a), cow1, cow2): return True
    if not cow2 and x != b and f(b, a, b, t + abs(x-b), cow1, cow2): return True
    return False


if f(0, a, b, 0, False, False):
    print("possible")
else:
    print("impossible")