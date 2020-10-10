T = int(input())        #test case

for i in range(T):
    N = int(input())
    arr = list(map(int, list(input()))) #for each character
    #print(arr)
    count = [0] * 10
    for j in range(N):
        count[arr[j]] += 1
    
    max = -1
    max_val = 0
    for j in range(10):
        if max_val < count[j]:
            max = j
            max_val = count[j]
        elif max_val == count[j]:   #duplicate
            if max < j:             #get a bigger number
                max = j
    
    print("#%d %d %d "%(i + 1, max, max_val))

