import heapq

def solution(scores):
    answer = 1
    
    target = [scores[0][0], scores[0][1]]
    tsum = target[0] + target[1]
    
    scores = list(map(lambda x: [-x[0], x[1]], scores))
    
    heapq.heapify(scores)
    
    maxfir = -scores[0][0]
    maxsec = -1
    while scores:
        temp = heapq.heappop(scores)
        temp[0] *= (-1)
        if maxsec < temp[1]:
            maxfir = temp[0]
            maxsec = temp[1]
        if temp[0] < maxfir and temp[1] < maxsec:
            if temp[0] == target[0] and temp[1] == target[1]:
                return -1
            continue
        elif temp[0] + temp[1] > tsum:
            answer += 1
    return answer