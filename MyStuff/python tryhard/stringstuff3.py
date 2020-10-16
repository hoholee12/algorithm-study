T = int(input())

for i in range(1, T + 1):
    str1 = dict.fromkeys(list(input()), 0)
    str2 = list(input())

    for j in str2:
        try:
            str1[j] += 1
        except:
            pass

    max = 0
    for j in list(str1.values()):
        if max < j:
            max = j
    
    print("#%d %d"%(i, max))
