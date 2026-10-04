def solution(people, limit):
    answer = 0
    people.sort() # 몸무게를 오름차순으로 정렬
    
    left = 0
    right = len(people) - 1
    
    while left <= right:
        # 가장 가벼운 사람과 가장 무거운 사람의 합이 limit 이하인 경우 (두 명 탑승)
        if people[left] + people[right] <= limit:
            left += 1
            right -= 1
        # limit을 초과하는 경우 (가장 무거운 사람 혼자 탑승)
        else:
            right -= 1
        
        # 보트 한 대 추가
        answer += 1
        
    return answer
