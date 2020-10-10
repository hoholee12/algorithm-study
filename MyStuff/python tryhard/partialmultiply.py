T = int(input())

for i in range(T):
    N, M = map(int, input().split())
    V = []
    for j in input().split():
        V += [int(j)]
    V.sort()
    #print(V)

    min = 1
    for j in range(M):
        min += V[j]
    #print("min:", min)
    max = 1
    for j in range(N - 1, N - 1 - M, -1):   #index be careful!!
        max += V[j]
    #print("max:", max)
    print("#%d %d"%(i + 1, max - min))
