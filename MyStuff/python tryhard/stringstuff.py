T = int(input())

for i in range(1, T + 1):
    pattern = list(input())
    arr = list(input())

    #boyer-moore algorithm
    index = 0
    prev_index = index
    found = False
    while True:
        prev_index = index

        #check oor
        if index + len(pattern) - 1 >= len(arr):
            break
        #match pattern
        count = len(pattern)
        for j in range(len(pattern) - 1, -1, -1):
            if arr[index + j] == pattern[j]:
                count -= 1
            else:   #no match
                break
        #found!
        if count == 0:
            found = True
            break

        #if character exists in pattern
        alien = True
        for j in range(len(pattern)):
            #print(pattern[j], arr[index + len(pattern) - 1])
            if pattern[j] == arr[index + len(pattern) - 1]:
                alien = False
                index += len(pattern) - j - 1
                break
                
        
        #if alien character
        if alien:
            index += len(pattern)

        if index >= len(arr):
            break
            

    if found:
        print("#%d 1"%(i))
    else:
        print("#%d 0"%(i))