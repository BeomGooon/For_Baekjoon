def solution(land):
    # 두 번째 행부터 마지막 행까지 내려가며 DP 진행
    for i in range(1, len(land)):
        # 현재 행의 각 열에 대해, 직전 행에서 같은 열을 제외한 최댓값을 더해줌
        land[i][0] += max(land[i-1][1], land[i-1][2], land[i-1][3])
        land[i][1] += max(land[i-1][0], land[i-1][2], land[i-1][3])
        land[i][2] += max(land[i-1][0], land[i-1][1], land[i-1][3])
        land[i][3] += max(land[i-1][0], land[i-1][1], land[i-1][2])
        
    # 마지막 행의 최댓값이 최종 얻을 수 있는 최대 점수
    return max(land[-1])
