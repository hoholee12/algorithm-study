T = int(input())

for i in range(1, T + 1):
    N, K = map(int, input().split())
    #N = array
    #K = target sum
    count = 0

    for j in range(1<<N):
        sum = 0
        for k in range(N):
            if j & (1<<k):
                #print(str(k + 1), end=",")
                sum += k + 1
        #print("sum:", sum)
        if sum == K:
            count += 1
    print("#%d %d"%(i, count))

