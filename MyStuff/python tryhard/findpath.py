T = int(input())

def dfs(start):
    global V
    global result
    global VISITED
    global MAP
    global END_NODE
    VISITED[start] = 1

    stack = [start]
    #print(stack)
    
    while stack:
        vertex = stack.pop()
        for i in range(1, V + 1):
            if MAP[vertex][i] == 1 and VISITED[i] != 1:
                if i == END_NODE:    #found end
                    result = 1
                    return

                stack += [i]    #push
                VISITED[i] = 1  #visited

        #print(stack)
            
for i in range(1, T + 1):
    V, E = map(int, input().split())

    MAP = [[0] * (V + 1) for _ in range(V + 1)]
    VISITED = [0] * (V + 1)
    for j in range(E):
        START, END = map(int, input().split())
        MAP[START][END] = 1

    START_NODE, END_NODE = map(int, input().split())
    result = 0
    dfs(START_NODE)

    print("#%d %d"%(i, result))

