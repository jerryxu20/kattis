import collections

s = input()
first = s[0]

st = set(s)
n = int(input())

words = [input() for _ in range(n)]

def valid(word):
   if first not in word or len(word) < 4:
      return False
   for c in word:
      if c not in st:
         return False
   return True

for word in words:
   if valid(word):
      print(word)