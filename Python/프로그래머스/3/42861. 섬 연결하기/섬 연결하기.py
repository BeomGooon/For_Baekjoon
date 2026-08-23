import heapq
from copy import deepcopy

def solution(n, costs):
    answer = 0
    while costs:
        new_cost = []
        bridge = [[-1]*50 for _ in range(50)]
        pq = []
        cnum = 0
        connected = [-1]*n
        for item in costs:
            heapq.heappush(pq, (item[2], item[0], item[1]))
        while pq:
            temp = heapq.heappop(pq)
            # print(f"{temp[1]}-{temp[2]}: {temp[0]}")
            if connected[temp[1]] == -1 and connected[temp[2]] == -1:
                # print("cnum added")
                answer += temp[0]
                connected[temp[1]] = cnum
                connected[temp[2]] = cnum
                cnum += 1
            elif connected[temp[1]] == -1:
                answer += temp[0]
                connected[temp[1]] = connected[temp[2]]
            elif connected[temp[2]] == -1:
                answer += temp[0]
                connected[temp[2]] = connected[temp[1]]
            elif connected[temp[1]] != connected[temp[2]]:
                g1 = connected[temp[1]]
                g2 = connected[temp[2]]
                if g1 > g2:
                    tem = g1
                    g1 = g2
                    g2 = tem
                if bridge[g1][g2] == -1 or bridge[g1][g2] > temp[0]:
                    bridge[g1][g2] = temp[0]
                    # print(f"bridge added: {g1}-{g2}: {temp[0]}")
                    new_cost.append([g1, g2, temp[0]])
        # print(f"cnum: {cnum}")
        # print("phase end")
        costs = deepcopy(new_cost)
    return answer