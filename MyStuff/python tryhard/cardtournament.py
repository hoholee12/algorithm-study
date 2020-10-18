T = int(input())

def winner(arr, L, R):
    if L == R:
            return arr[L]
    else:
        #divide
        wl = winner(arr, L, (L + R) // 2)
        wr = winner(arr, (L + R) // 2 + 1, R)
        #conquer
        if wl == 1 and wr ==3:
            return wl
        elif wl < wr:
            return wr
        else:
            return wl

for i in range(1, T + 1):
    N = int(input())
    arr = list(map(int, input().split()))

    result = winner(arr, 0, len(arr) - 1)
    print("#%d %d"%(i, result))
