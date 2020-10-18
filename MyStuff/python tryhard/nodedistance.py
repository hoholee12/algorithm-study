T = int(input())

def bfs(graph, start, end):
    global V
    global gsum

    queue = [(start, [start])]
    while queue:
        vertex, path = queue.pop(0)

        for next in graph[vertex] - set(path):
            if next == end:
                lsum = len(path)
                if gsum > lsum:
                    gsum = lsum
                    return
            else:
                queue.append((next, path + [next]))
       


def dfs(graph, i, end, lsum, C = None):
    global V
    global gsum



    #case 0
    if C is None:
        C = [0] * (V + 1)
        C[i] = 1

    #case 1
    if i == end:
        if gsum > lsum:
            gsum = lsum
        return
    
    #case 2
    for x in graph[i]:
        #visited check
        if C[x] == 1:
            continue

        C[x] = 1
        dfs(graph, x, end, lsum + 1, C)
        C[x] = 0

    return


for i in range(1, T + 1):
    V, E = map(int, input().split())
    graph = {i:set() for i in range(1, V + 1)}

    for _ in range(E):
        a, b = map(int, input().split())
        #undirected graph
        graph[a].add(b)
        graph[b].add(a)

    start, end = map(int, input().split())

    gsum = V * E + 12
    bfs(graph, start, end)

    if gsum == V * E + 12:
        gsum = 0
    print("#%d %d"%(i, gsum))

