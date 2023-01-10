n = int(input())
for _ in range(n):
    simon = input()
    if simon.startswith("Simon says"):
        print(simon.split("Simon says")[-1].strip())
