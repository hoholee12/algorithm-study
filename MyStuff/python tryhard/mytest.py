T = int(input())
arr = []
for i in range(T):
    N = int(input())
    min = 100000000
    max = 0
    for j in input().split():
        arr += [int(j)]
    for j in range(N):
        if arr[j] < min:
            min = arr[j]
        if arr[j] > max:
            max = arr[j]
    print("#" + str(i + 1) + " " + str(max - min))