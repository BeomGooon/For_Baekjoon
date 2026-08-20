dp = [0] * 100001

def fib(n):
    if n < 2:
        return n
    elif dp[n] != 0:
        return dp[n]
    else:
        res = (fib(n-2) + fib(n-1)) % 1234567
        dp[n] = res
        return res

def solution(n):
    ind = 1000
    while ind < n:
        fib(ind)
        ind += 1000
    answer = fib(n)
    return answer