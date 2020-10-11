T = int(input())

def bsearch(arr, L, R, target):
    C = int((L + R) / 2)
    
    if arr[C] == target:
        return 1
    elif arr[L] <= target and arr[C] > target:
        #print("LEFT %d %d %d"%(arr[L], arr[C - 1], target))
        return bsearch(arr, L, C, target) + 1
    elif arr[C] <= target and arr[R] >= target:
        #print("RIGHT %d %d %d"%(arr[C], arr[R], target))
        return bsearch(arr, C, R, target) + 1

for i in range(1, T + 1):
    N, A, B = map(int, input().split())
    arr = [i for i in range(1, N + 1)]
    Acount = bsearch(arr, 0, N - 1, A)
    Bcount = bsearch(arr, 0, N - 1, B)
    if Acount > Bcount:
        print("#%d B"%(i))
    elif Acount < Bcount:
        print("#%d A"%(i))
    else:
        print("#%d 0"%(i))

