from collections import deque

def sim(w1, w2):
    n = len(w1)
    flag = False
    for i in range(n):
        if w1[i] != w2[i]:
            if flag:
                return False
            else:
                flag = True
    return flag
        
def solution(begin, target, words):
    tind = -1
    matrix = [[0] * len(words) for _ in range(len(words))]
    from_begin = []
    for i in range(len(words)):
        if target == words[i]:
            tind = i
        if sim(begin, words[i]):
            from_begin.append(i)
        for j in range(i + 1, len(words)):
            if sim(words[i], words[j]):
                matrix[i][j] = 1
                matrix[j][i] = 1
    if tind == -1 or not from_begin:
        return 0
    dq = deque()
    for ind in from_begin:
        dq.append((ind, 1, [ind]))
    while dq:
        ind, temp, lis = dq.popleft()
        if ind == tind:
            return temp
        for i in range(len(words)):
            if ind != i and matrix[ind][i] == 1 and i not in lis:
                dq.append((i, temp + 1, lis + [i]))
    return 0