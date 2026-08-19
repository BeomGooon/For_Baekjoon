def solution(arr, l, r):
    # 1. 블록별 시작/끝 인덱스 및 누적 정보 전처리
    # prefix_len[i]: i번째 블록까지의 누적 원소 개수 (1-indexed)
    prefix_len = [0]
    for x in arr:
        prefix_len.append(prefix_len[-1] + x)
    
    total_len = prefix_len[-1]
    
    # 2. 특정 구간 [start, end] (1-indexed)의 합을 구하는 헬퍼 함수
    def get_range_sum(start, end):
        import bisect
        # start와 end가 속한 블록 인덱스 찾기
        idx_s = bisect.bisect_left(prefix_len, start)
        idx_e = bisect.bisect_left(prefix_len, end)
        
        if idx_s == idx_e:
            return (end - start + 1) * arr[idx_s - 1]
        
        # 첫 번째 걸친 블록 합
        s = (prefix_len[idx_s] - start + 1) * arr[idx_s - 1]
        # 마지막 걸친 블록 합
        s += (end - prefix_len[idx_e - 1]) * arr[idx_e - 1]
        # 중간에 온전히 포함된 블록들의 합
        for i in range(idx_s, idx_e - 1):
            s += arr[i] * arr[i]
        return s

    result_sum = get_range_sum(l, r)
    wlen = r - l + 1
    
    # 3. 투 포인터를 이용해 윈도우를 이동시키며 result_sum과 일치하는 구간 카운트
    # left_idx: 윈도우 시작점이 속한 블록, right_idx: 윈도우 끝점이 속한 블록
    result_num = 0
    
    left_block = 0
    right_block = 0
    
    # 초기 윈도우: [1, wlen]
    import bisect
    left_block = bisect.bisect_left(prefix_len, 1) - 1
    right_block = bisect.bisect_left(prefix_len, wlen) - 1
    
    # 현재 윈도우 [cur_l, cur_r]의 합
    current_sum = get_range_sum(1, wlen)
    if current_sum == result_sum:
        result_num += 1
        
    cur_l = 1
    cur_r = wlen
    
    while cur_r < total_len:
        # 다음 블록 경계까지 남은 거리 계산
        dist_l = prefix_len[left_block + 1] - cur_l + 1
        dist_r = prefix_len[right_block + 1] - cur_r
        
        step = min(dist_l, dist_r)
        if step == 0:
            step = 1
            
        v_left = arr[left_block]
        v_right = arr[right_block]
        
        diff = v_right - v_left
        
        # step만큼 한 번에 이동하면서 result_sum을 만족하는 지점 개수 계산
        if step > 1:
            if diff == 0:
                if current_sum == result_sum:
                    result_num += (step - 1)
            else:
                # current_sum + k * diff == result_sum 을 만족하는 정수 1 <= k < step 탐색
                rem = result_sum - current_sum
                if rem % diff == 0:
                    k = rem // diff
                    if 1 <= k < step:
                        result_num += 1
                        
            current_sum += diff * (step - 1)
            cur_l += (step - 1)
            cur_r += (step - 1)
            
        # 1칸 추가 이동하여 경계 갱신
        cur_l += 1
        cur_r += 1
        current_sum += (arr[bisect.bisect_left(prefix_len, cur_r) - 1] - arr[left_block])
        
        if cur_l > prefix_len[left_block + 1]:
            left_block += 1
        if cur_r > prefix_len[right_block + 1]:
            right_block += 1
            
        if current_sum == result_sum:
            result_num += 1

    return [result_sum, result_num]