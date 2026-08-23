from math import ceil

def solution(n, stations, w):
    answer = 0

    start = 1
    for item in stations:
        end = item - (w + 1)
        if start > end:
            start = item + (w + 1)
            continue
        else:
            # print(f"start: {start}, end: {end}, res: {ceil((end - start + 1) / (2 * w + 1))}")
            answer += ceil((end - start + 1) / (2 * w + 1))
            start = item + (w + 1)
    if start <= n:
        # print(f"start: {start}, end: {n}, res: {ceil((n - start + 1) / (2 * w + 1))}")
        answer += ceil((n - start + 1) / (2 * w + 1))
            
    return answer