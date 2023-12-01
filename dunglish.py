import collections

n = int(input())
words = input().split()

m = int(input())

good_mp = collections.defaultdict(list)
bad_mp = collections.defaultdict(list)
for _ in range(m):
    s, trans, good = input().split()
    if good == "correct":
        good_mp[s].append(trans)
    else:
        bad_mp[s].append(trans)

right = 1
wrong = 1

for word in words:
    right *= len(good_mp[word])
    wrong *= len(good_mp[word]) + len(bad_mp[word])

wrong -= right

if right + wrong == 1:
    for word in words:
        try:
            print(bad_mp[word][0], end=" ")
        except:
            print(good_mp[word][0], end=" ")
    print()
    print("correct" if right else "incorrect")
else: 
    print(right, "correct")
    print(wrong, "incorrect") 