from collections import deque

def solution(n, roads, sources, destination):
    answer = []
    lis = [[]for _ in range(n)]
    minlis = [-1]*n
    for item in roads:
        i1 = item[0] - 1
        i2 = item[1] - 1
        lis[i1].append(i2)
        lis[i2].append(i1)
    dq = deque()
    dq.append((0, destination - 1))
    minlis[destination-1] = 0
    while dq:
        temp = dq.popleft()
        for next in lis[temp[1]]:
            if minlis[next] == -1:
                minlis[next] = temp[0] + 1
                dq.append((temp[0] + 1, next))
    answer = [minlis[i-1] for i in sources]
    return answer