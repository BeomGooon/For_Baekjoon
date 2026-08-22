from copy import copy

def solution(triangle):
    h = len(triangle)
    lis = [0] * h
    lis[0] = triangle[0][0]
    for i in range(1, h):
        temp = []
        temp.append(lis[0] + triangle[i][0])
        for j in range(1, i + 1):
            temp.append(max(lis[j], lis[j-1]) + triangle[i][j])
        temp.append(0)
        lis = copy(temp)
    return max(lis)