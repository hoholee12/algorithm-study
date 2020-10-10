X, Y = map(int, input().split())
list2d = [[0 for i in range(X)] for j in range(Y)]
print(list2d)

mylist = []
mylist += [list(map(int, input().split())) for j in range(Y)]
newlist = [list(filter(lambda slist: True if slist == 2 else False, xlist)) for xlist in mylist]
print(mylist)
print(newlist)


for j in range(len(mylist)):
    print(mylist[j])

#delta search (search neighbors, becareful with index)
arr = [[i for i in range(3)] for j in range(3)]
dx = [0, 0, -1 , 1]
dy = [-1, 1, 0, 0]

for x in range(len(arr) - 1):
    for y in range(len(arr[x]) - 1):
        for i in range(4):
            testx = x + dx[i]
            testy = y + dy[i]
            #(0, -1), (0, 1), (-1, 0), (1, 0)

            print(arr[testx][testy], end=" ")
        print()

alpha = [1, 2, 3]
val = ['a', 'b', 'c']

alpha_index = list(zip(alpha, val))     #zips them into a tuple
print(alpha_index)

arr_index = list(zip(*arr))     #dereference, passing varargs, useful for making transposed matrix
print(arr_index)