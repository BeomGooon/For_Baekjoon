def solution(n, s):
    answer = []
    a = s // n
    m = s % n
    if a == 0:
        return [-1]
    for i in range(n):
        answer.append(a)
    for i in range(n-1,n-m-1,-1):
        answer[i] += 1
    return answer