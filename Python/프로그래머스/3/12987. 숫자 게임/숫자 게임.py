import heapq

def solution (A, B):
    heapq.heapify(A)
    heapq.heapify(B)

    answer = 0 # 승점
    target = heapq.heappop(A)
    while B:
        cur = heapq.heappop(B)
        if cur > target: # 승점 1점
            answer += 1
            if A:
                target = heapq.heappop(A)
    return answer