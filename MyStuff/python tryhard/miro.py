T = int(input())

def findstart(matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            if matrix[i][j] == 2:
                return (i, j)
    return None

#delta search
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def findpath(matrix, x, y):
    if matrix[x][y] == 1:
        return 0
    elif matrix[x][y] == 3:
        return 1
    else:
        rtval = 0
        matrix[x][y] = 1    #block road aka visited
        for i in range(len(dx)):
            rtval += findpath(matrix, x + dx[i], y + dy[i])
        return rtval


for i in range(1, T + 1):
    N = int(input())

    matrix = [list(1 for _ in range(N + 2))]
    for j in range(N):
        minput = list(map(int, list(input())))
        matrix.append([1] + minput + [1])
    matrix.append([1 for _ in range(N + 2)])

    print(matrix)

    #find start
    startx, starty = findstart(matrix)
    if findpath(matrix, startx, starty) > 0:
        print("#%d 1"%(i))
    else:
        print("#%d 0"%(i))
