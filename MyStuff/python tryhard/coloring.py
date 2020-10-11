
T = int(input())
for i in range(1, T + 1):
    arr = [[0 for i in range(10)] for j in range(10)]

    N = int(input())
    inputarr = []
    for j in range(N):
        inputarr += [list(map(int, input().split()))]
        
    count = 0
    for x in inputarr:
        x1, y1, x2, y2 = x[0], x[1], x[2], x[3]
        color = x[4]

        #draw
        for k in range(10): #x
            for l in range(10): #y
                if x1 <= k and x2 >= k and y1 <= l and y2 >= l:
                    if arr[k][l] != 0 and color != arr[k][l]:
                        arr[k][l] += color
                        count += 1
                    elif arr[k][l] == 0:
                        arr[k][l] = color

    print("#%d %d"%(i, count))