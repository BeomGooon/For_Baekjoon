from itertools import product

def cmp_str(str1, str2):
    if len(str1) != len(str2):
        return False
    for i in range(len(str1)):
        if str1[i] != str2[i] and str2[i] != "*":
            return False
    return True

def solution(user_id, banned_id):
    answer = 0
    lis = [[] for _ in range(len(banned_id))]

    for i in range(len(banned_id)):
        for j in range(len(user_id)):
            if cmp_str(user_id[j], banned_id[i]):
                lis[i].append(j)
    
    products = list(product(*lis))
    allset = set()
    for item in products:
        temset = set()
        for i in item:
            temset.add(i)
        if len(temset) == len(item):
            temtuple = tuple(sorted(temset))
            if temtuple not in allset:
                allset.add(temtuple)
                # print(list(user_id[i] for i in temtuple))
                answer += 1
    return answer