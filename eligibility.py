n = int(input())


for _ in range(n):
    name, school, birth, courses = input().split()
    def valid():
        year = int(school.split('/')[0])
        if year >= 2010: return 1
        year = int(birth.split('/')[0])
        if year >= 1991: return 1
        if int(courses)/5 > 8: return 2
        return 3
    res = valid()
    if res == 1:
        print(name, "eligible")
    elif res == 2:
        print(name, "ineligible")
    else:
        print(name, "coach petitions")