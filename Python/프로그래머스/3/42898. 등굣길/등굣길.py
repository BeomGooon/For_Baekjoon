from collections import deque

def solution(m, n, puddles):
    mat = [[0]*m for _ in range(n)]
    mat[0][0] = 1
    for item in puddles:
        mat[item[1]-1][item[0]-1] = -1
    dq = deque()
    dq.append((0, 0))
    for i in range(m+n-2):
        for y in range(min(i + 1, n)):
            x = i - y
            if x >= m or mat[y][x] == -1:
                continue
            if y + 1 < n and mat[y+1][x] != -1:
                mat[y+1][x] += mat[y][x]
                mat[y+1][x] %= 1000000007
            if x + 1 < m and mat[y][x+1] != -1:
                mat[y][x+1] += mat[y][x]
                mat[y][x+1] %= 1000000007
    for item in mat:
        print(item)
    return mat[n-1][m-1] % 1000000007