def solution(n, times):
    answer = 0
    times.sort()
    left = 1
    right = times[-1] * n
    while True:
        mid = (right + left) // 2
        # print(f"mid: {mid}")
        temp = 0
        for item in times:
            temp += mid // item
        # print(f"temp: {temp}")
        if temp >= n and right > left:
            right = mid
        elif temp < n:
            left = mid + 1
        else:
            answer = mid
            break
    return answer