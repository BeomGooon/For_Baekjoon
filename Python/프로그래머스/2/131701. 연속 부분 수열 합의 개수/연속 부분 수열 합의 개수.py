from collections import deque

def solution(elements):
    num = len(elements)
    elements.extend(elements[:-1])
    answer = set()
    for i in range(1, num + 1):
        ind = 0
        temp_sum = 0
        dq = deque()
        while ind < num + i - 1:
            dq.append(elements[ind])
            temp_sum += elements[ind]
            if ind >= i:
                temp_sum -= dq.popleft()
            answer.add(temp_sum)
            ind += 1
    return len(answer)