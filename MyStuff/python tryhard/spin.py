T = int(input())

for i in range(1, T + 1):
    N, M = map(int, input().split())

    C = list(map(int, input().split()))

    for _ in range(M):
        temp = C.pop(0)
        C += [temp]
    print("#%d %d"%(i, C[0]))