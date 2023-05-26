board = [[list('...') if (i + j) % 2 == 0 else list(':::') for j in range(8)] for i in range(8)]
white = input()[7:].split(',')
black = input()[7:].split(',')
for piece in white:
    if not piece: continue
    i = 8 - int(piece[-1])
    j = ord(piece[-2]) - ord('a')
    x = piece[-3].upper() if len(piece) == 3 else 'P'
    board[i][j][1] = x
for piece in black:
    if not piece: continue
    i = 8 - int(piece[-1])
    j = ord(piece[-2]) - ord('a')
    x = piece[-3].lower() if len(piece) == 3 else 'p'
    board[i][j][1] = x
    
border = "+---+---+---+---+---+---+---+---+"
for row in board:
    print(border)
    print("|".join(['', *["".join(x) for x in row], '']))
print(border)
    