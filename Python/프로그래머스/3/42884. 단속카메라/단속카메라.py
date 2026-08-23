import heapq
from copy import copy

def solution(routes):
    answer = 0
    heapq.heapify(routes)

    cur_range = []
    while routes:
        temp = heapq.heappop(routes)
        if not cur_range or (temp[0] > cur_range[1]):
            cur_range = copy(temp)
            answer += 1
        else:
            cur_range = [max(temp[0], cur_range[0]), min(temp[1], cur_range[1])]

    return answer