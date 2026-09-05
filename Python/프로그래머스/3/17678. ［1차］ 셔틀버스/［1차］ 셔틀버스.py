def solution(n, t, m, timetable):
    answer = ''
    ans_min = 0
    
    # 0시0분 기준 분 단위 시간(int)으로 변형 및 sort
    timetable = list(map(lambda x: int(x[0:2]) * 60 + int(x[3:]), timetable))
    timetable.sort()
    
    start = 0
    time = 540
    tlen = len(timetable)
    for i in range(n):
        num = 0
        while start < tlen and timetable[start] <= time and num < m:
            start += 1
            num += 1
        
        if i == n-1:
            if m == num:
                ans_min = timetable[start-1] - 1
            else:
                ans_min = time
            
        time += t
    
    answer = f"{ans_min//600}{(ans_min//60)%10}:{(ans_min%60)//10}{(ans_min%60)%10}"
    
    return answer