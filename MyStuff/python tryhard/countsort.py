
import makelist

mylist = makelist.mylist
emptylist = makelist.emptylist
initcount = makelist.initcount

count = initcount(mylist)

mylist = emptylist(mylist)
j = 0
for i in range(10):
    if count[i] != 0:
        for x in range(count[i]):
            mylist[j] = i
            j += 1

print(mylist)
    