
try:
    f = open("input.txt", "rt")
except:
    exit()

#get data into list
mylist = []
for i in f.read(6):
    mylist += [int(i)]
print("original list:", mylist)

def swap(mylist, i, j):
    temp = mylist[i]
    mylist[i] = mylist[j]
    mylist[j] = temp

def initcount(mylist):
    count = []
    for i in range(10):     #0~9 map
        count += [0]

    for i in mylist:
        count[i] += 1
    return count

def emptylist(mylist):
    mylist = [0] * 6
    return mylist