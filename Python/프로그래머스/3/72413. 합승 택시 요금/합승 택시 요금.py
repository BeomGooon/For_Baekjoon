import heapq

def solution(n, s, a, b, fares):
    answer = float('inf')
    
    pqa = []
    pqb = []
    pqs = []
    
    fare_list_a = [float('inf')] * (n+1)
    fare_list_b = [float('inf')] * (n+1)
    fare_list_s = [float('inf')] * (n+1)
    
    to_list = [[] for _ in range(n+1)]
    for item in fares:
        id1 = item[0]
        id2 = item[1]
        fare = item[2]
        to_list[id1].append((id2, fare))
        to_list[id2].append((id1, fare))
    
    
    heapq.heappush(pqa, (a, 0))
    while pqa:
        it = heapq.heappop(pqa)
        now = it[0]
        fare = it[1]
        if fare < fare_list_a[now]:
            fare_list_a[now] = fare
            for item in to_list[now]:
                heapq.heappush(pqa, (item[0], fare+item[1]))
    
    heapq.heappush(pqb, (b, 0))
    while pqb:
        it = heapq.heappop(pqb)
        now = it[0]
        fare = it[1]
        if fare < fare_list_b[now]:
            fare_list_b[now] = fare
            for item in to_list[now]:
                heapq.heappush(pqb, (item[0], fare+item[1]))
                
    heapq.heappush(pqs, (s, 0))
    while pqs:
        it = heapq.heappop(pqs)
        now = it[0]
        fare = it[1]
        if fare < fare_list_s[now]:
            fare_list_s[now] = fare
            for item in to_list[now]:
                heapq.heappush(pqs, (item[0], fare+item[1]))
    
    
    for i in range(1, n+1):
        temp = 0
        temp += fare_list_a[i]
        temp += fare_list_b[i]
        temp += fare_list_s[i]
        answer = min(answer, temp)
    return answer