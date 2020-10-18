#n queen problem





#powerset generator
def construct_candidates_ps(arr, k, myinput, C):     #binary
    C[0] = 1
    C[1] = 0
    return 2                                    #binary for loop

def backtrack_ps(arr, k, myinput):
    C = [0] * 2     #max candidates = 2 (binary)
    if k == myinput:
        print(arr)    #end of nodes
    else:
        k += 1
        for i in range(construct_candidates_ps(arr, k, myinput, C)):
            arr[k] = C[i]
            backtrack_ps(arr, k, myinput)

backtrack_ps([0] * 4, 0, 3)


#permutation generator
def construct_candidates_pm(arr, k, myinput, C):
    perm = [False for _ in range(4)]
    for i in range(1, k):
        perm[arr[i]] = True

    ncandidates = 0
    for i in range(1, myinput + 1):
        if perm[i] == False:
            C[ncandidates] = i
            ncandidates += 1

    return ncandidates

def backtrack_pm(arr, k, myinput):
    C = [0] * 4
    if k == myinput:
        print(arr)    #end of nodes
    else:
        k += 1
        for i in range(construct_candidates_pm(arr, k, myinput, C)):
            arr[k] = C[i]
            backtrack_pm(arr, k, myinput)

backtrack_pm([0] * 4, 0, 3)
