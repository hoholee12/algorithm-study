T = int(input())

for i in range(1, T + 1):
    A = list(input())

    stack = []

    for j in range(0, len(A)):
        if len(stack) == 0:
            stack += A[j]
            continue
        else:
            popped = stack.pop()

        if popped != A[j]:
            stack += popped
            stack += A[j]
        else:
            pass
        
    print("#%d %d"%(i, len(stack)))
