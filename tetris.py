
profiles = [[], [0]]

class Piece:
    def __init__(self, piece):
            self.piece = piece
            
    def profile(self):
        p = [5 for _ in range(len(self.piece[0]))]
        for row, i in zip(self.piece, range(len(self.piece))):
            for c, j in zip(row, range(len(row))):
                if c == '#':
                    p[j] = min(p[j], i)
        return p
    
    def rotate(self):
        list_of_tuples = zip(*self.piece[::-1])
        self.piece =  [list(elem) for elem in list_of_tuples]
        
    def __str__(self):
        ans = ""
        for row in self.piece:
            ans += "".join(row)
            ans += '\n'
        return ans[:-1]
# ###0
# 5670
# 5900

# 55#
# 96#
# 07#
# 000
        
pieces = [[], ["####"], ["##", "##"], ["##_", "_##"], ["_##", "##_"], ["###", "_#_"], ["###", "__#"], ["###", "#__"]]
c, idx = map(int, input().split())
board = list(map(int, input().split()))
p = Piece(pieces[idx])
seen = set()
ans = 0
for _ in range(4):
    tup = tuple(tuple(x) for x in p.piece)
    if tup not in seen:
        prof = p.profile()
        for i in range(c - len(prof) + 1):
            negative = board[i: i + len(prof)]
            mn = min(negative)
            negative = [x - mn for x in negative]
            # print(prof)
            # print(negative)
            # print(board[i: i + len(prof)])
            # print()
            if prof == negative:
                ans += 1
    seen.add(tup)
    p.rotate()
print(ans)