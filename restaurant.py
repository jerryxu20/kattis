while True:
    n = int(input())
    stack1 = 0
    stack2 = 0
    if n == 0: break
    for _ in range(n):
        command, m = input().split()
        m = int(m)
        if command == "DROP":
            stack1 += m
            print("DROP 1", m)
        else:
            if stack2 > 0:
                cap = min(m, stack2)
                m -= cap
                stack2 -= cap
                print("TAKE 2", cap)
            if m > 0:
                print("MOVE 1->2", stack1)
                stack2 = stack1 - m
                print("TAKE 2", m)
                stack1 = 0
    print()