from collections import deque

def solution(stones, k):
    answer = 200000000
    dq = deque()
    for ind, item in enumerate(stones):
        if ind < k:
            # 값(item)을 넣는 알고리즘
            while dq:
                temp = dq[-1]
                if stones[temp] > item:
                    break
                else:
                    dq.pop()
            dq.append(ind)
            #print(f"now index: {ind}, numdq: {list(map(lambda x: stones[x], dq))}")
        else: # 가장 앞 인덱스를 확인하고 슬라이드에서 벗어난 범위면 제거하는 과정을 앞에 추가
            temp = dq[0]
            if temp <= ind - k:
                dq.popleft()
            # 값(item)을 넣는 알고리즘
            while dq:
                temp = dq[-1]
                if stones[temp] > item:
                    break
                else:
                    dq.pop()
            dq.append(ind)
            #print(f"now index: {ind}, numdq: {list(map(lambda x: stones[x], dq))}")
        if ind >= k - 1: # 윈도우가 완성됨 따라서 정답과 비교 후 업데이트 진행
            temp = dq[0]
            if answer > stones[temp]:
                answer = stones[temp]
    return answer