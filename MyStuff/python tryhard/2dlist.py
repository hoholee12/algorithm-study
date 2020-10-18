'''
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
'''
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

#partial set
bit = [0 for i in range(4)]
for i in range(2):
    bit[0] = i
    for j in range(2):
        bit[1] = j
        for k in range(2):
            bit[2] = k
            for l in range(2):
                bit[3] = l
                print(bit)

#partial set 2
arr = [3, 6, 7, 1, 5, 4]
n = len(arr)
for i in range(1<<n):
    #print("i:", bin(i))
    for j in range(n):
        #print("\tj:", bin(j))
        if i & (1<<j):
            #print("\t\ti & 1<<j:", bin(i & (1<<j)))
            #print(i, 1<<j, end = ", ")
            print(arr[j], end=",")
    print()

#search
