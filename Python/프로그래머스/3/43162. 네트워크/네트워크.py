def dfs(edges, networks, ind, net_num):
    if networks[ind] == 0:
        # print(f"cur: ({ind}, {net_num})")
        networks[ind] = net_num
        for i in edges[ind]:
            dfs(edges, networks, i, net_num)
    return None

def solution(n, computers):
    edges = []
    networks = []
    for i in range(n):
        edges.append(list())
        networks.append(0)
    for ind, com in enumerate(computers):
        for i in range(n):
            if com[i] == 1 and i != ind:
                edges[ind].append(i)

    # print(edges)  
    answer = 0
    for i in range(n):
        if networks[i] == 0:
            answer += 1
            dfs(edges, networks, i, answer)
    return answer