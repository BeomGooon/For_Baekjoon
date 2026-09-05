from collections import deque

def solution(k, dungeons):
    answer = -1
    dq = deque()
    dq.append((k, 0, 0))    # 남은 피로도, 갔다온 던전 수, 비트 인덱스
    while dq:
        temp = dq.popleft()
        # print(temp)
        left = temp[0]
        num = temp[1]
        bit_ind = temp[2]
        answer = num
        t = 1
        for ind, item in enumerate(dungeons):
            if left >= item[0] and (t & bit_ind) == 0:
                dq.append((left - item[1], num + 1, (bit_ind | t)))
            
            t *= 2
        
    return answer