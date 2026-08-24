def solution(sequence):
    answer = 0
    
    cur_max1 = 0
    cur_max2 = 0
    for ind, item in enumerate(sequence):
        i1 = item * (1 if ind % 2 == 0 else -1)
        i2 = item * (-1 if ind % 2 == 0 else 1)
        
        cur_max1 = max(i1, cur_max1 + i1)
        cur_max2 = max(i2, cur_max2 + i2)
        
        answer = max(answer, cur_max1, cur_max2)
        
    return answer