#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <queue>

using namespace std;

const int RIGHT = 0;
const int DOWN = 1;
const int LEFT = 2;
const int UP = 3;


int solution(vector<string> board) {
    int answer = 0;
    vector<vector<bool>> bool_board;
    int board_row = board.size();
    int board_col = board[0].size();
    vector<bool> wall_row;
    vector<bool> temp;   
    pair<int, int> redpos;
    pair<int, int> greenpos;
    for (int i = 0; i < board_col + 2; i++) {
        wall_row.push_back(true);
    }
    bool_board.push_back(wall_row);
    for (int i = 0; i < board_row; i++) {
        temp.push_back(true);
        for (int j = 0; j < board_col; j++) {
            if (board[i][j] == 'D') {
                temp.push_back(true);
            }
            else {temp.push_back(false);}
            if (board[i][j] == 'R') {
                redpos = {i+1, j+1};
            }
            if (board[i][j] == 'G') {
                greenpos = {i+1, j+1};
            }
        }
        temp.push_back(true);
        bool_board.push_back(temp);
        temp.clear();
    }
    bool_board.push_back(wall_row);
    
    // 빠른 이동을 위한 {특정 위치 + 특정 방향}의 다음 위치 저장(memoization)
    pair<int, int> next_pos[102][102][4];
    for (int i = 1; i < board_row + 1; i++) {
        for (int j = 1; j < board_col + 1; j++) {
            if (bool_board[i-1][j]) { // 위쪽에 벽
                int shift = 0;
                while (!bool_board[i+shift][j]) {
                    next_pos[i+shift][j][UP] = {i, j};
                    shift++;
                }
            }
            if (bool_board[i][j+1]) { // 오른쪽에 벽
                int shift = 0;
                while (!bool_board[i][j-shift]) {
                    next_pos[i][j-shift][RIGHT] = {i, j};
                    shift++;
                }
            }
            if (bool_board[i+1][j]) { // 아래쪽에 벽
                int shift = 0;
                while (!bool_board[i-shift][j]) {
                    next_pos[i-shift][j][DOWN] = {i, j};
                    shift++;
                }
            }
            if (bool_board[i][j-1]) { // 왼쪽에 벽
                int shift = 0;
                while (!bool_board[i][j+shift]) {
                    next_pos[i][j+shift][LEFT] = {i, j};
                    shift++;
                }
            }
        }
    }
    // printf("{%d, %d}\n", next_pos[1][7][LEFT].first, next_pos[1][7][LEFT].second);
    // BFS 알고리즘 사용
    bool visited[102][102];
    queue<vector<int>> que; // {움직인 횟수, y좌표, x좌표}
    vector<int> temp_bfs;
    temp_bfs.push_back(0);
    temp_bfs.push_back(redpos.first);
    temp_bfs.push_back(redpos.second);
    que.push(temp_bfs);
    temp_bfs.clear();
    while (!que.empty()) {
        temp_bfs = que.front();
        que.pop();
        int dis = temp_bfs[0];
        int cur_y = temp_bfs[1];
        int cur_x = temp_bfs[2];
        temp_bfs.clear();
        // printf("dis: %d, cur_y: %d, cur_x: %d\n", dis, cur_y, cur_x);
        if (cur_y == greenpos.first && cur_x == greenpos.second) {
            return dis;
        }
        for (int i = 0; i < 4; i++) {
            pair<int, int> next_yx = next_pos[cur_y][cur_x][i];
            if (!visited[next_yx.first][next_yx.second]) {
                visited[next_yx.first][next_yx.second] = true;
                temp_bfs.push_back(dis+1);
                temp_bfs.push_back(next_yx.first);
                temp_bfs.push_back(next_yx.second);
                que.push(temp_bfs);
                temp_bfs.clear();
            }
        }
        
    }
    return -1;
}