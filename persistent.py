def factor(a):
    ans = []
    if a <= 9:
        return [a]
    for i in range(9,1, -1):
        while a % i == 0:
            ans.append(i);
            a //= i
    if a > 1:
        ans.append(a)
    return ans

while True:
    a = int(input())
    if a == -1:
        break
    if a == 0:
        print(10)
        continue
    fact = factor(a)
    if len(fact) == 1:
        fact.append(1)
    fact.sort()
    if fact[-1] > 9:
        print("There is no such number.")
    else:
        print(*fact,sep="")