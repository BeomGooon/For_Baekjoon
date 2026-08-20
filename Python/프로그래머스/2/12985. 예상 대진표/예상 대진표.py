def round(num):
    ind = 1
    res = 0
    while ind <= num:
        ind *= 2
        res += 1
    return res

def solution(n,a,b):
    temp = (a - 1) ^ (b - 1)
    answer = round(temp)

    return answer