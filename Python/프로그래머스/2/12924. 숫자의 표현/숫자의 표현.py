from math import sqrt, floor

def max_len(n):
    n *= 2
    n += 0.25
    return floor(sqrt(n) - 0.5)

def solution(n):
    answer = 0
    mlen = max_len(n)
    for i in range(1, mlen + 1):
        temp = (i - i * i + 2 * n) / (2 * i)
        if temp.is_integer():
            answer += 1
            
    return answer