from collections import defaultdict
import heapq

def solution(genres, plays):
    answer = []
    gdic = defaultdict(int)
    pdic = defaultdict(list)
    n = len(genres)
    for i in range(n):
        gdic[genres[i]] -= plays[i]
        heapq.heappush(pdic[genres[i]], (-plays[i], i))
    glis = []
    for genre, value in gdic.items():
        heapq.heappush(glis, (value, genre))
    while glis:
        genre = heapq.heappop(glis)[1]
        num = 0
        while pdic[genre] and num < 2:
            answer.append(heapq.heappop(pdic[genre])[1])
            num += 1
    return answer