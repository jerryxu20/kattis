n = int(input())
ans = bin(n)[2:]
ans = ans[::-1]
print(int(ans, 2))