T = int(input())

#delta
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def findstart(arr):
    for y in range(len(arr)):
        for x in range(len(arr)):
            if arr[y][x] == 2:
                return (x, y)

def dfs(arr, x, y, sum):
    global mindistance
    global reachedend
    #case 0 wall
    if arr[y][x] == 1:
        return

    #case 1 finish
    if arr[y][x] == 3:
        reachedend = True
        if sum - 1 < mindistance:
            mindistance = sum - 1
        return
    
    #case 2 dfs
    arr[y][x] = 1 #visited
    for i in range(4):
        dfs(arr, x + dx[i], y + dy[i], sum + 1)


for i in range(1, T + 1):
    N = int(input())

    arr = [list(1 for _ in range(N + 2))]
    for j in range(N):
        arr += [[1] + list(map(int, input())) + [1]]
    arr += [list(1 for _ in range(N + 2))]

    startx, starty = findstart(arr)

    mindistance = 10 * N
    reachedend = False
    dfs(arr, startx, starty, 0)
    if reachedend:
        print("#%d %d"%(i, mindistance))
    else:
        print("#%d 0"%(i))