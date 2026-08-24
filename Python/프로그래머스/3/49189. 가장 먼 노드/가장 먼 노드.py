from collections import deque

def solution(n, edge):
    answer = 0
    dq = deque()
    matrix = [set() for _ in range(n + 1)]
    for item in edge:
        i1 = item[0]
        i2 = item[1]
        matrix[i1].add(i2)
        matrix[i2].add(i1)
    dq.append((1, 0))
    touched = [False] * (n + 1)
    touched[1] = True
    maxdis = 0
    while dq:
        temp = dq.popleft()
        ind = temp[0]
        dis = temp[1]
        if dis > maxdis:
            # print(f"new distance found. index: {ind}, distance: {dis}")
            maxdis = dis
            answer = 1
        elif dis == maxdis:
            # print(f"same maximum distance found. index: {ind}, distance: {dis}")
            answer += 1
        for next in matrix[ind]:
            if not touched[next]:
                touched[next] = True
                dq.append((next, dis + 1))
    return answer