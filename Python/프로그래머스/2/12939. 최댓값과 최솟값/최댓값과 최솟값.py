from copy import deepcopy
def solution(s):
    lis = map(int, s.split(' '))
    lis2 = deepcopy(lis)
    answer = f"{max(lis)}"
    answer = f"{min(lis2)} " + answer
    return answer