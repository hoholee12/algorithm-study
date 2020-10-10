T = int(input())
arr = []
for i in range(T):
    count = 0
    K, N, M = map(int, input().split())

    temparr = [0] + list(map(int, input().split())) + [N]

    
    #0 1 3 7 8 9 10 - temparr
    # 1 2 4 1 1 1 - arr(fail)
    # 1 3 7
    #     4 -fail

    #0 4 7 9 14 17 20 - temparr
    # 4 3 2 5  3  3 - arr
    # 4 7
    #   3 5 10
    #       5  8
    #          3  6
    #             3

    skip = False
    arr = []
    for j in range(M + 1):
        temp = temparr[j + 1] - temparr[j]
        if temp > K:
            skip = True
            break
        arr += [temp]
    #print(arr)
    if skip != True:
        xarr = []
        for j in range(M):
            xarr += [arr[j + 1] + arr[j]]
        #print(xarr)

        count = 0    
        for j in range(M):
            if xarr[j] > K:
                count += 1
    
    print("#%d %d"%(i + 1, count))
