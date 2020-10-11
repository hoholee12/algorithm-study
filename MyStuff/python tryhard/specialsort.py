T = int(input())

def swap(arr, x, y):
    temp = arr[x]
    arr[x] = arr[y]
    arr[y] = temp

for i in range(1, T + 1):
    N = int(input())
    inputarr = list(map(int, input().split()))
    #selection sort fits for this kind of sort
    flag = False
    for j in range(N):
        swapme = 0
        if flag:
            flag = False
            smallest = 100
            for k in range(j, N):
                if inputarr[k] < smallest:
                    smallest = inputarr[k]
                    swapme = k
        else:
            flag = True
            biggest = 1
            for k in range(j, N):
                if inputarr[k] > biggest:
                    biggest = inputarr[k]
                    swapme = k
        
        swap(inputarr, j, swapme)

    print("#" + str(i), end=" ")
    for j in range(10):
        print("%d "%(inputarr[j]), end="")
    print()
