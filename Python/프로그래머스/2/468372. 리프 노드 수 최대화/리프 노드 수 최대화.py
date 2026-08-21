def solution(dist_limit, split_limit):
    max_leaves = 1
    
    # 2^x * 3^y <= split_limit 를 만족하는 모든 (x, y) 조합 탐색
    # 제한사항이 10^9 이므로 x는 0~29, y는 0~18 까지만 탐색하면 충분합니다.
    for x in range(30):
        for y in range(19):
            if (2 ** x) * (3 ** y) <= split_limit:
                
                # 최적의 분배 순서: 2를 먼저 배치하고 3을 나중에 배치
                seq = [2] * x + [3] * y
                
                leaves = 1          # 현재 리프 노드 수 (초기 루트 1개)
                cap = 1             # 현재 깊이에서 확장 가능한 노드의 최대 개수
                rem = dist_limit    # 남은 분배 노드 개수
                
                # 위에서부터 아래로 트리를 확장(Greedy)
                for b in seq:
                    if rem == 0:
                        break
                    
                    # 확장할 노드 수: 현재 레벨의 노드 전부를 확장하거나, 예산(rem)만큼만 확장
                    e = min(cap, rem)
                    
                    # b개의 자식을 분배하면 기존 노드 1개가 사라지고 b개가 생기므로 (b - 1)개 증가
                    leaves += e * (b - 1) 
                    
                    # 남은 분배 노드 차감 및 다음 레벨의 최대 확장 가능치(cap) 갱신
                    rem -= e
                    cap = e * b
                    
                # 최댓값 갱신
                if leaves > max_leaves:
                    max_leaves = leaves
                    
    return max_leaves