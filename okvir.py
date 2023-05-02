pattern = "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#."
n, m = map(int, input().split())
u, l, r, d = map(int, input().split())
height = u + d + n
width = l + r + m
halfw = l + m
word = [input().strip() for _ in range(n)]
for i in range(height):
    if i < u or i + d >= height:
        print(pattern[i%2:i%2 + width])
    else:
        p = (i + halfw) % 2
        print(pattern[i%2:i%2 + l], word[i - u], pattern[p:p + r], sep="")


