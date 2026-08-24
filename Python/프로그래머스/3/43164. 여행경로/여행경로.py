from collections import deque
import bisect
from copy import deepcopy

def solution(tickets):
    idict = dict()
    ndict = dict()
    dlen = 0
    num = len(tickets) + 1
    nextlist = [[] for _ in range(num)]
    for ind, item in enumerate(tickets):
        fr = item[0]
        to = item[1]
        if fr not in idict:
            idict[fr] = dlen
            ndict[dlen] = fr
            dlen += 1
        if to not in idict:
            idict[to] = dlen
            ndict[dlen] = to
            dlen += 1
        bisect.insort(nextlist[idict[fr]], (to, ind))
        
    dq = deque()
    touch = [False] * len(tickets)
    dq.append((idict["ICN"], ["ICN"], touch))
    # print(ndict)
    while dq:
        temp = dq.popleft()
        ind = temp[0]
        cur = temp[1]
        touched = temp[2]
        for next, index in nextlist[ind][::-1]:
            next = idict[next]
            if touched[index] == False:
                # print(f"from: {ndict[ind]}, to: {ndict[next]}, line no {index}")
                curcopy = deepcopy(cur)
                curcopy.append(ndict[next])
                touchedcopy = deepcopy(touched)
                touchedcopy[index] = True
                dq.append((next, curcopy, touchedcopy))
        if len(cur) == num:
            # print(f"finished: {cur}")
            answer = deepcopy(cur)
    
    return answer