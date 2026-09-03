import heapq

def solution(board):
    N = len(board)
    # 4방향 정의: 우(0), 하(1), 좌(2), 상(3)
    dy = [0, 1, 0, -1]
    dx = [1, 0, -1, 0]
    
    # dist[y][x][direction]: 각 위치와 방향별 최소 비용 저장 (무한대로 초기화)
    INF = float('inf')
    dist = [[[INF] * 4 for _ in range(N)] for _ in range(N)]
    
    pq = []
    
    # 시작점 (0, 0)에서 동쪽(0)과 남쪽(1)으로 출발 가능하도록 설정
    # 처음 이동은 코너가 없으므로 100원이 아니라 0원에서 시작하여 다음 칸에서 100원을 더해줍니다.
    # 큐 데이터 구조: (비용, y, x, 이전 방향)
    if board[0][1] == 0:
        heapq.heappush(pq, (0, 0, 0, 0))
        dist[0][0][0] = 0
    if board[1][0] == 0:
        heapq.heappush(pq, (0, 0, 0, 1))
        dist[0][0][1] = 0
        
    while pq:
        cost, y, x, d = heapq.heappop(pq)
        
        # 도착점에 도달했을 때의 최소 비용 리턴 (다익스트라이므로 처음 꺼내진 게 최솟값)
        if y == N - 1 and x == N - 1:
            return cost
            
        # 이미 더 적은 비용으로 방문한 적이 있다면 스킵
        if dist[y][x][d] < cost:
            continue
            
        # 현재 방향(d)을 기준으로 다음 4방향 탐색
        for next_d in range(4):
            # 후진(180도 회전)은 불필요하므로 제외
            if (d + 2) % 4 == next_d:
                continue
                
            ny = y + dy[next_d]
            nx = x + dx[next_d]
            
            # 격자 범위 내이고 벽(1)이 아닌 경우
            if 0 <= ny < N and 0 <= nx < N and board[ny][nx] == 0:
                # 같은 방향이면 직선(100), 다른 방향이면 코너(600)
                next_cost = cost + (100 if d == next_d else 600)
                
                # 새로 계산한 비용이 기존에 기록된 비용보다 작을 때만 갱신 후 큐에 삽입
                if next_cost < dist[ny][nx][next_d]:
                    dist[ny][nx][next_d] = next_cost
                    heapq.heappush(pq, (next_cost, ny, nx, next_d))
                    
    return 0
