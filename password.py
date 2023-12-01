n = int(input())

prob = []
for _ in range(n):
    prob.append(float(input().split()[1]))
    
prob.sort(reverse=True)
print(prob)
total = 1
def f(idx):
    global total
    if idx == n - 1: return 1
    good = prob[idx]/total
    bad = 1 - good
    total -= prob[idx]
    return good + (1 + f(idx + 1)) * bad

print(f(0))

