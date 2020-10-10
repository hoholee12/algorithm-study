
import makelist

mylist = makelist.mylist
swap = makelist.swap


for j in range(5):
    for i in range(j, 5):
        if mylist[i] > mylist[i + 1]:
            swap(mylist, i, i + 1)

print(mylist)