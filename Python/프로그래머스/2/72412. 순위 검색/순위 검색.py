import bisect
from itertools import product
query_dict = {"-": 0, "cpp": 1, "java": 2, "python": 3, "backend": 1, "frontend": 2, "junior": 1, "senior": 2, "chicken": 1, "pizza": 2}

def count_greater_or_equal(lst, x):
    idx = bisect.bisect_left(lst, x)
    return len(lst) - idx

# 1st: -, cpp, java, python
# 2nd: -, backend, frontend
# 3rd: -, junior, senior
# 4th: -, chicken, pizza
def solution(info, query):
    db = [[[[[] for _ in range(3)] for _ in range(3)] for _ in range(3)] for _ in range(4)]
    for item in info:
        words = item.split(' ')
        col = [['-', i] for i in words[:-1]]
        pro = list(product(*col))
        grade = int(words[4])
        for case in pro:
            temp = (query_dict[case[0]], query_dict[case[1]], query_dict[case[2]], query_dict[case[3]])
            bisect.insort(db[temp[0]][temp[1]][temp[2]][temp[3]], grade)

    answer = []
    for item in query:
        words = item.split(' ')
        grade = int(words[-1])
        words = words[::2]
        ind = (query_dict[words[0]], query_dict[words[1]], query_dict[words[2]], query_dict[words[3]])
        answer.append(count_greater_or_equal(db[ind[0]][ind[1]][ind[2]][ind[3]], grade))

    return answer