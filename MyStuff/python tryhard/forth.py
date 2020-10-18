T = int(input())

for i in range(1, T + 1):
    tmpstr = list(input().split())

    stack = []
    while tmpstr:
        tmp = tmpstr.pop(0)
        if tmp == ".":
            if len(stack) == 1:
                print("#%d %d"%(i, stack.pop()))
            else:
                print("#%d error"%(i))
            break
        elif tmp.isdigit():
            stack += [tmp]
        elif len(stack) < 2:
            print("#%d error"%(i))
            break
        elif tmp == "-":
            b = int(stack.pop())
            a = int(stack.pop())
            stack += [a - b]
        elif tmp == "+":
            b = int(stack.pop())
            a = int(stack.pop())
            stack += [a + b]
        elif tmp == "/":
            b = int(stack.pop())
            a = int(stack.pop())
            stack += [a // b]
        elif tmp == "*":
            b = int(stack.pop())
            a = int(stack.pop())
            stack += [a * b]
        