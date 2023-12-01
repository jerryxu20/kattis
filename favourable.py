T = int(input())


for _ in range(T):
    ending = {}
    adj = [[] for _ in range(401)]
    n = int(input())
    for __ in range(n):
        s = input().split()
        if len(s) == 4:
            s = [int(x) for x in s]
            for i in range(1, 4):
                adj[s[0]].append(s[i])
        else:
            ending[int(s[0])] = int(s[1] == "favourably")

    def dfs(node):
        ans = 0
        if node in ending:
            return ending[node]
        for nxt in adj[node]:
            ans += dfs(nxt)
        ending[node] = ans
        return ans
    
    print(dfs(1))
        