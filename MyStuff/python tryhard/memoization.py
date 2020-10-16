#memoization is storing previous calculated results
#and reuse, like dp

#recursive
def fibo(n):
    global memo
    if n >= 2 and len(memo) <= n:
        memo.append(fibo(n - 2) + fibo(n - 1))
    return memo[n]

memo = [0, 1]

print(fibo(10))

print(memo)   #memoization

#iterative
def fibo2(n):
    f = [0, 1]
    for i in range(2, n + 1):
        f.append(f[i - 2] + f[i - 1])
    return f[n]

print(fibo2(10))