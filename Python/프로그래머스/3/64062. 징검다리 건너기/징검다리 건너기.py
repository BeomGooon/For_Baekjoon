from collections import deque

def solution(stones, k):
    answer = 200000000
    dq = deque()
    for ind, item in enumerate(stones):
        if ind < k:
            while dq:
                temp = dq[-1]
                if stones[temp] > item:
                    break
                else:
                    dq.pop()
            dq.append(ind)
            #print(f"now index: {ind}, numdq: {list(map(lambda x: stones[x], dq))}")
        else:
            temp = dq.popleft()
            if temp > ind - k:
                dq.appendleft(temp)
            while dq:
                temp = dq[-1]
                if stones[temp] > item:
                    break
                else:
                    dq.pop()
            dq.append(ind)
            #print(f"now index: {ind}, numdq: {list(map(lambda x: stones[x], dq))}")
        if ind >= k - 1:
            temp = dq.popleft()
            if answer > stones[temp]:
                answer = stones[temp]
            dq.appendleft(temp)
    return answer