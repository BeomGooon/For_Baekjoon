import heapq

def solution(jobs):
    answer = 0
    heapq.heapify(jobs)
    pq = []
    time = 0
    ind = 0
    total = len(jobs)
    left = total
    while left:
        if jobs and jobs[0][0] <= time:
            while jobs and jobs[0][0] <= time:
                temp = heapq.heappop(jobs)
                heapq.heappush(pq, (temp[1], temp[0], ind))
                ind += 1
        if pq:
            tjob = heapq.heappop(pq)
            time += tjob[0]
            answer += (time - tjob[1])
            left -= 1
        else:
            time = jobs[0][0]
            
    return answer // total