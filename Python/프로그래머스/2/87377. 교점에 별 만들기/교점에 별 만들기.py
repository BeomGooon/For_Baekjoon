from itertools import combinations
from math import isclose

def get_point(l1, l2):
    a, b, c = l1
    d, e, f = l2
    if isclose(a*e, b*d):
        return None
    elif a == 0:
        if d == 0:
            return None
        y = - (c / b)
        x = (c * e - b * f) / (b * d)
    elif b == 0:
        if e == 0:
            return None
        x = - (c / a)
        y = (c * d - a * f) / (a * e)
    else:
        y = (c * d - a * f) / (a * e - b * d)
        x = (c * e - b * f) / (b * d - a * e)

    if isclose(x, round(x)) and isclose(y, round(y)):
        return (round(x), round(y))
    else:
        return None

def solution(lines):
    miny = float('inf')
    minx = float('inf')
    maxy = float('-inf')
    maxx = float('-inf')
    comb = combinations(lines, 2)
    resset = set()
    for l1, l2 in comb:
        temp = get_point(l1, l2)
        if temp:
            resset.add(temp)
            tx = temp[0]
            ty = temp[1]
            if miny > ty:
                miny = ty
            if maxy < ty:
                maxy = ty
            if minx > tx:
                minx = tx
            if maxx < tx:
                maxx = tx
    height = maxy - miny + 1
    width = maxx - minx + 1
    answer = []
    for i in range(height):
        line_temp = ""
        for j in range(width):
            if (minx + j, maxy - i) in resset:
                line_temp += "*"
            else:
                line_temp += "."
        answer.append(line_temp)
    return answer