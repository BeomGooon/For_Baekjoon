from functools import cache

dp = [[1, 2, 2, 3, 4],[0, 1, 1, 2, 3],[0, 0, 0, 1, 2],[0, 0, 0, 1, 2],[0, 0, 0, 0, 1]]

@cache
def dac(n, i1, i2):
    if n == 0:
        return 1
    in1 = i1 // 5
    in2 = i2 // 5
    res = 0
    if in1 == in2:
        return dac(n-1, in1, in1) * dp[i1%5][i2%5]
    else:
        res += 4 * dac(n-1, in1 + 1, in2 - 1)
        res += dac(n-1, in1, in1) * dp[i1%5][4]
        res += dac(n-1, in2, in2) * dp[0][i2%5]
        return res

def solution(n, l, r):
    answer = dac(n, l-1, r-1)
    return answer