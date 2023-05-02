def isprime(n):
   if n <= 2:
      return True
   if n % 2 == 0:
      return False
   div = 3
   while(div * div <= n):
      if n % div == 0:
         return False
      div += 2
   if n:
      return True
   return False
         
while True:
   p, a = map(int, input().split())
   if p == 0 and a == 0: break
   b = pow(a, p, p)
   if a == b and not isprime(p):
      print("yes")
   else:
      print("no")