T = int(input())

for i in range(1, T + 1):
    N, M = map(int, input().split())
    arr = []
    for j in range(N):
        arr += [list(k for k in list(input()))]

    result = []

    skip = False
    #master
    for y in range(N):
        if skip:
            break
        for offset in range(N - M + 1): #at least 1 loop
            if skip:
                break
            resultx = []
            for x in range(M // 2):
                if arr[y][x + offset] != arr[y][M - 1 - x + offset]:
                    break
                else:
                    resultx += [arr[y][x + offset]]



            #if it works then push and end
            if len(resultx) == M // 2:
                result = resultx
                result += [resultx[a] for a in range(len(resultx) - 1, -1, -1)]
                print("#%d "%(i), end="")
                for j in range(len(result)):
                    print(result[j], end="")
                print()
                skip = True

    #other axis
    for x in range(N):
        if skip:
            break
        for offset in range(N - M + 1): #at least 1 loop
            if skip:
                break
            resulty = []
            for y in range(M // 2):
                if arr[y + offset][x] != arr[M - 1 - y + offset][x]:
                    break
                else:
                    resulty += [arr[y + offset][x]]



            #if it works then push and end
            if len(resulty) == M // 2:
                result = resulty
                result += [resulty[a] for a in range(len(resulty) - 1, -1, -1)]
                print("#%d "%(i), end="")
                for j in range(len(result)):
                    print(result[j], end="")
                print()
                skip = True
            

