def solution(n):
    answer = 0
    full_mask = (1 << n) - 1

    def dfs(row, cols, diag1, diag2):
        nonlocal answer
        if row == n:
            answer += 1
            return

        # 현재 행에서 퀸을 놓을 수 있는 자리 구하기
        # (cols | diag1 | diag2)의 결과에서 0인 자리가 놓을 수 있는 자리임
        # ~ 연산자로 반전시킨 후 full_mask와 & 연산하여 유효 비트만 남김
        available_slots = full_mask & ~(cols | diag1 | diag2)

        while available_slots:
            # 가장 오른쪽에 있는 1 비트 하나만 추출 (퀸을 놓을 자리)
            curr_bit = available_slots & -available_slots
            
            # 선택한 비트를 다음 재귀로 넘겨줌
            # 다음 행으로 갈 때, 대각선 비트들은 각각 한 칸씩 시프트 해줌
            dfs(
                row + 1, 
                cols | curr_bit, 
                (diag1 | curr_bit) << 1, 
                (diag2 | curr_bit) >> 1
            )
            
            # 처리한 비트는 제거하고 다음 가능한 자리 탐색
            available_slots &= available_slots - 1

    dfs(0, 0, 0, 0)
    return answer
