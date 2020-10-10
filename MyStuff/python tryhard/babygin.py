import makelist

mylist = makelist.mylist
initcount = makelist.initcount


#babygin -greedy
is_babygin = 0

# status
status = [0, 0] #triplet, run
triplet = 0
run = 0

def checkrun(count, status):
    keeprunning = True
    while keeprunning:
        keeprunning = False
        temp = 0
        for i in range(10):     #0~9 map
            if temp >= 3:
                status[1] += 1
                temp = 0
            if count[i] >= 1:
                count[i] -= 1   #delete run along the way
                temp += 1
                keeprunning = True
            else:
                temp = 0
    print("after checking run:", count)

def checktriplet(count, status):
    for i in range(10):         #0~9 map
        if count[i] >= 3:
            status[0] += int(count[i] / 3)
            count[i] -= 3
    print("after checking triplet:", count)


#main check
for mode in range(2):
    count = initcount(mylist)
    print(count)
    if mode == 0:
        checkrun(count, status)
        checktriplet(count, status)
    else:
        checktriplet(count, status)
        checkrun(count, status)

    

    #check
    triplet, run = status
    print("triplet:", triplet, "run:", run)

    if run > 0 and triplet > 0:
        is_babygin += 1
    elif run > 1 or triplet > 1:
        is_babygin += 1

    status = [0, 0]


if is_babygin > 0:
    print("its a babygin!")
else:
    print("its not a babygin :(")