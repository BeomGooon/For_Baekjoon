from functools import cache

@cache
def dac(i, fr, tr): # i개의 원판을 fr 인덱스에서 tr 인덱스로 옮기는 과정 return
    if i == 1:
        return [[fr, tr]]
    rem = 6 - (fr + tr) # 나머지 하나의 인덱스. fr -> rem -> tr
    res = [*(dac(i-1, fr, rem)), [fr, tr], *(dac(i-1, rem, tr))]
    return res

def solution(n):
    answer = dac(n, 1, 3)
    return answer