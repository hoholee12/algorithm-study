T = int(input())

for i in range(1, T + 1):
    str = list(input())
    stack = []
    failflag = False
    ignoreflag = False
    for j in str:
        if ignoreflag:
            if j == '\'':
                ignoreflag = False
            continue

        if j == '(':
            stack += j
        elif j == '{':
            stack += j
        elif j == '[':
            stack += j
        
        elif j == ')':
            if len(stack) == 0:
                failflag = True
                break
            if stack.pop() != '(':
                failflag = True
                break
        elif j == '}':
            if len(stack) == 0:
                failflag = True
                break
            if stack.pop() != '{':
                failflag = True
                break
        elif j == ']':
            if len(stack) == 0:
                failflag = True
                break
            if stack.pop() != '[':
                failflag = True
                break

        elif j == '\'':
            ignoreflag = True
    
    if len(stack) != 0:
        failflag = True

    if failflag:
        print("#%d %d"%(i, 0))
    else:
        print("#%d %d"%(i, 1))