def solution(gems):
    # 최악의 경우 (처음부터 끝까지)로 초기화
    answer = [1, len(gems)] 
    num_gems = len(set(gems))
    gem_dict = {}
    
    start = 0
    min_length = float('inf')
    
    for end, gem in enumerate(gems):
        # 1. end 포인터: 보석을 딕셔너리에 추가 (구간 확장)
        gem_dict[gem] = gem_dict.get(gem, 0) + 1
        
        # 2. 모든 종류의 보석을 포함하게 되면 start 포인터 이동 (구간 축소)
        while len(gem_dict) == num_gems:
            # 기존 최소 구간보다 더 짧은 구간을 찾으면 업데이트
            if (end - start) < min_length:
                min_length = end - start
                answer = [start + 1, end + 1]
            
            # start가 가리키는 보석을 하나 뺌
            start_gem = gems[start]
            gem_dict[start_gem] -= 1
            
            # 해당 보석의 개수가 0이 되면 딕셔너리에서 제거
            if gem_dict[start_gem] == 0:
                del gem_dict[start_gem]
            
            # start 포인터를 오른쪽으로 이동하여 구간을 줄임
            start += 1
            
    return answer