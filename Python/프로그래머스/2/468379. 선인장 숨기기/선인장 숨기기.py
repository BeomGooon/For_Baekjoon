from collections import deque
def solution(m, n, h, w, drops):
    INF = len(drops) + 1
    maps = [[INF]*n for _ in range(m)]
    
    best_rows = [[INF]*(n-w+1) for _ in range(m)]
    index = 0
    for i, j in drops:
        index += 1
        maps[i][j] = index
    
    for i in range(m):
        d = deque()
        for j in range(n):
            if d and d[0] < j - w + 1:
                d.popleft()
            while d and maps[i][d[-1]] > maps[i][j]:
                d.pop()
            d.append(j)
            
            if j >= w - 1:
                best_rows[i][j - w + 1] = maps[i][d[0]]
                # print(best_rows[i][j-w+1], end=' ')
        # print()
                
    best_num = 0
    best_y = 0
    best_x = 0
    for j in range(n - w + 1):
        d = deque()
        for i in range(m):
            if d and d[0] < i - h + 1:
                d.popleft()
            while d and best_rows[d[-1]][j] > best_rows[i][j]:
                d.pop()
            d.append(i)
            
            if i >= h - 1:
                if best_rows[d[0]][j] > best_num or (best_rows[d[0]][j] == best_num and best_y > d[0]):
                    best_num = best_rows[d[0]][j]
                    best_y = i - h + 1
                    best_x = j
                
    return [best_y, best_x]
                
        
            