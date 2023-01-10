while True:
    n = int(input())
    if n == 0:
        break;
    am = []
    pm = []
    for i in range(n):
        time, thing = input().split()
        hour, minute = time.split(':')
        hour = int(hour) % 12
        thing = thing.strip()
        if thing == 'a.m.':
            am.append((hour, minute))
        else:
            pm.append((hour, minute))
    am.sort()
    pm.sort()
    for hour, minute in am:
        if hour == 0:
            hour = 12
        print(f"{hour}:{minute} a.m.")
    for hour, minute in pm:
        if hour == 0:
            hour = 12
        print(f"{hour}:{minute} p.m.")