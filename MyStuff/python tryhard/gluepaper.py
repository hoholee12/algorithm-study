T = int(input())


data = [0 for _ in range(31)]       #N < 300

def dppaper(session):
    global data
    if not session:
        return 0
    elif session == 0:
        data[session] = 0
    elif session == 1:
        data[session] = 1
    elif session == 2:
        data[session] = 3
    else:
        data[session] = data[dppaper(session - 1)] + data[dppaper(session - 2)] * 2
    return session


for i in range(1, T + 1):
    data = [0 for _ in range(31)]
    N = int(input()) // 10
    session = dppaper(N)
    #print(data)
    print("#%d %d"%(i, data[session]))