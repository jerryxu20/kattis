while True:
    n, t = map(float, input().split())
    n = int(n)
    if n == 0: break
    total = 1 - t

    def f(n, cur):
        if n == 0: return cur
        nxt = f(n - 1, 2 * cur)
        # when is x * nxt >= cur
        x = max(t, cur/nxt)
        avg = (1 + x)/2        
        prob_go_next = (1 - min(x, 1)) / total 
        prob_quit = 1 - prob_go_next
        return prob_go_next * avg * nxt + prob_quit * cur

    print(format(f(n, 1), '.3f'))