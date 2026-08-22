import bisect

def solution(operations):
    answer = []
    lis = []
    n = 0
    maxlen = 0
    minlen = 0
    for item in operations:
        if item[0] == "I":
            bisect.insort(lis, int((item.split(' '))[-1]))
        elif item == "D 1" and lis:
            lis.pop()
        elif item == "D -1" and lis:
            lis = lis[1:]
    if not lis:
        return [0, 0]
    else:
        return [lis[-1], lis[0]]