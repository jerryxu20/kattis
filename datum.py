import datetime
day, month = map(int, input().split())
print(day, month)
date = datetime.datetime(2009, month, day)
days = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday']
print(days[date.weekday()])
