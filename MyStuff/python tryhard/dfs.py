
#python dict as adjacent list
graph = {'A': set(['B', 'C']),
         'B': set(['A', 'D', 'E']),
         'C': set(['A', 'F']),
         'D': set(['B']),
         'E': set(['B', 'F']),
         'F': set(['C', 'E'])}

#visited = set. only used internally. its not stack. its not indexed
#stack = list

#recursive
print("recursive dfs:")
def dfs(graph, start, visited=None):
    #case 1: make visited array
    if visited is None:
        visited = set()
    
    #case 2: mark node visited, if exists then gtfo
    if start not in visited:
        visited.add(start)
        print("<" + start, end=',')   #print top elements
    else:
        return      #dont revisit top elements that are already visited from bottom

    #ex) graph[A] -> B, C     and   visited -> ....., start
    #      graph[A] - visited = remaining graph[A] nodes unvisited
    
    #is: compare identity(pointer)
    #==: compare value

    #case 3: check for any nearby unvisited nodes
    if graph[start] - visited == set():
        print("EOF")
    else:
        print(graph[start] - visited)

    #case 3.5: recursion to said nodes
    for next in graph[start] - visited: #loop em through
        dfs(graph, next, visited)       #dig into it every loop (dfs)

dfs(graph, 'A')
print()





#iterative
print("iterative dfs:")
def dfs2(graph, start):
    #case 1: stack starts with first node inserted.
    visited, stack = set(), [start]
    
    #loop
    while stack:
        #case 2: pop node from stack
        vertex = stack.pop()

        #case 3: mark node visited, if exists then gtfo
        if vertex not in visited:
            visited.add(vertex)
            print("<" + vertex, end=",")
        else:
            continue

        #list.append(): add the array itself to list. O(1)
        #list.extend(): add the each elements of array into iterable list. O(N)
        
        #case 4: check for any nearby unvisited nodes
        if graph[vertex] - visited == set():
            print("EOF")
        else:
            print(graph[vertex] - visited)

        #case 5: push said nodes to stack
        stack.extend(graph[vertex] - visited)   #stack unvisited nodes


dfs2(graph, 'A')
print()





#path
print("iterative dfs path:")
def dfs_paths(graph, start, goal):

    #case 1: stack starts with first pair of node, and visited list(first node visited)
    stack = [(start, [start])]

    #loop
    while stack:
        #case 2: pop node and visited list from stack
        (vertex, path) = stack.pop()

        #skip case 3

        #case 4: check for goal WHILE appending to stack
        for next in graph[vertex] - set(path):
            if next == goal:
                yield path + [next] #generator: returns value but not over yet
                                    #this is to find multiple possible paths
            else:
                stack.append((next, path + [next]))
                #append to stack to look further(dfs)

print(list(dfs_paths(graph, 'A', 'F')))