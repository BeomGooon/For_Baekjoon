from functools import cache


def solution(n, results):
    graph = [[0] * n for i in range(n)]
    results = list(map(lambda x: [x[0]-1, x[1]-1], results))
    
    for win, los in results:
        graph[win][los] = 1
        graph[los][win] = -1
    
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if graph[i][k] == graph[k][j] and graph[i][k] != 0:
                    graph[i][j] = graph[i][k]
                    graph[j][i] = graph[k][i]
    
    answer = 0
    for i in range(n):
        temp = 0
        for j in range(n):
            if graph[i][j] != 0:
                temp += 1
        if temp == n-1:
            answer += 1
    
    return answer
    