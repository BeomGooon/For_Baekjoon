from itertools import combinations
def solution(cost, hint):
    advantages = [[cost[i][0] - cost[i][j] for j in range(len(cost))]for i in range(len(cost))]
    # print(advantages)
    
    basic_cost = sum(cost[i][0] for i in range(len(cost)))
    
    max_advantage = 0
    for i in range(len(cost)):
        for combo in combinations(hint, i):
            hint_cost = 0
            hints = [0] * len(cost)
            temp_advantage = 0
            for temp_list in combo:
                hint_cost += temp_list[0]
                for stage in temp_list[1:]:
                    hints[stage - 1] += 1
                    
            for i in range(len(hints)):
                temp_advantage += advantages[i][min(hints[i], len(hint))]
            if temp_advantage - hint_cost > max_advantage:
                max_advantage = temp_advantage - hint_cost
    
    answer = basic_cost - max_advantage
    return answer