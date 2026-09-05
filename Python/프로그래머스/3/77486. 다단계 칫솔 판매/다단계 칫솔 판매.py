def solution(enroll, referral, seller, amount):
    answer = [0] * len(enroll)
    name_dict = {"-": -1}
    level_dict = {"-": 0}
    level_name = [[] for i in range(10000)]
    max_level = 0
    for ind, item in enumerate(enroll):
        name_dict[item] = ind
        ref = referral[ind]
        temp_level = 0
        
        temp_level = level_dict[ref] + 1
        level_name[temp_level].append(item)
        level_dict[item] = temp_level
        
        if temp_level > max_level:
            max_level = temp_level
        
    n = len(seller)
    for ind in range(n):
        me = name_dict[seller[ind]]
        parent = name_dict[referral[me]]
        price = amount[ind] * 100
        answer[me] += price
        while price:
            price = price // 10
            answer[me] -= price
            if parent == -1:
                break
            answer[parent] += price
            me = parent
            parent = name_dict[referral[me]]
        #print(f"ind: {ind}, answer: {answer}")
    
    return answer