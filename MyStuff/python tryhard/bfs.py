
#python dict as adjacent list
graph = {'A': set(['B', 'C']),
         'B': set(['A', 'D', 'E']),
         'C': set(['A', 'F']),
         'D': set(['B']),
         'E': set(['B', 'F']),
         'F': set(['C', 'E'])}

#top is pushed into queue
#on pop, all of its subnodes are pushed into queue
#all top nodes are visited, and subnodes remain in queue.

#iterative
print("iterative bfs:")
def bfs2(graph, start):
    #case 1: stack starts with first node inserted.
    visited, queue = set(), [start]
    
    #loop
    while queue:
        #case 2: pop node from queue
        vertex = queue.pop(0)

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

        #case 5: push said nodes to queue
        queue.extend(graph[vertex] - visited)   #queue unvisited nodes

print(bfs2(graph, 'A'))
print()



#path
print("iterative bfs path:")
def bfs_paths(graph, start, goal):

    #case 1: queue starts with first pair of node, and visited list(first node visited)
    queue = [(start, [start])]

    #loop
    while queue:
        #case 2: pop node and visited list from queue
        (vertex, path) = queue.pop(0)

        #skip case 3

        #case 4: check for goal WHILE appending to stack
        for next in graph[vertex] - set(path):
            if next == goal:
                yield path + [next] #generator: returns value but not over yet
                                    #this is to find multiple possible paths
            else:
                queue.append((next, path + [next]))
                #append to queue to look further(bfs)

print(list(bfs_paths(graph, 'A', 'F')))




#bfs is best for undirected, unweighted graph.

#return very first match and be done with it
print("shortest path using bfs:")
def shortest_path(graph, start, goal):
    try:
        return next(bfs_paths(graph, start, goal))  #next: returns next item from iterator
    except StopIteration:
        return None

print(shortest_path(graph, 'A', 'F'))
