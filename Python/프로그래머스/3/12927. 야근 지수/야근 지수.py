import heapq

def solution(n, works):
    works = list(map(lambda x: -x, works))
    heapq.heapify(works)

    temp = heapq.heappop(works)
    while n > 0 and temp != 0:
        n -= 1
        temp += 1
        heapq.heappush(works, temp)
        temp = heapq.heappop(works)
    heapq.heappush(works, temp)

    # print(works)
    answer = sum(map(lambda x: x**2, works))
    return answer