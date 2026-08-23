import heapq

def solution (A, B):
    heapq.heapify(A)
    heapq.heapify(B)

    answer = 0
    a = heapq.heappop(A)
    while B:
        b = heapq.heappop(B)
        if b > a:
            answer += 1
            if A:
                a = heapq.heappop(A)
            else:
                return answer
    return answer