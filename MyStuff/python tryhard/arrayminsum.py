T = int(input())

#arr: whole graph, sum, x:iterator, y:checkthis, visited
def dfs(arr, sum, x, y, visited):
    #case 0 init
    if not visited:
        visited = [0 for i in range(len(arr))]
    global min

    #case 1 reached end
    if x == len(arr):
        if min > sum:
            #set min
            min = sum
        return

    #case 2 prunning
    if min <= sum:
        return

    #case 3 do dfs
    prev_sum = sum
    for i in range(len(visited)):
        #skip already visited
        if visited[i] == 1:
            continue

        #sessions
        sum += arr[i][x]
        visited[i] = 1
        #dfs: x is iter
        dfs(arr, sum, x + 1, i, visited)
        #reset session for another one
        sum = prev_sum
        visited[i] = 0

for i in range(1, T + 1):
    N = int(input())
    arr = []
    for j in range(N):
        arr.append(list(map(int, input().split())))
    
    #do sth
    min = 10 * N
    dfs(arr, 0, 0, 0, None)
    print("#%d %d"%(i, min))