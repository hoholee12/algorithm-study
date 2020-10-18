T = int(input())



for i in range(1, T + 1):
    N, M = map(int, input().split())

    inputarr = list(map(int, input().split()))
    #[id of pizza, remaining cheese]
    furnace = []
    found = -1
    count = 0
    while found == -1:

        if len(furnace) >= N or not inputarr:
            while len(furnace) >= N or not inputarr:
                temp2 = furnace.pop(0)
                if temp2[1] == 0:
                    if len(furnace) == 1:
                        found = furnace[0][0]
                        break
                    else:
                        continue
                temp2[1] //= 2
                furnace += [temp2]
        else:
            count += 1
            temp = inputarr.pop(0)
            furnace += [[count, temp]]

    print("#%d %d"%(i, found))


