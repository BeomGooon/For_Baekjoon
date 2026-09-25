#include <string>
#include <unordered_map>
#include <iostream>
#include <iostream>
using namespace std;

const int LEN = 11;

int solution(string dirs) {
    int answer = 0;
    bool passed[LEN][LEN][4] = {false, }; // 위치/방향 별로 이동했던 경로에 true 업데이트 (실제 y 및 x에 +5해서 계산)
    unordered_map<char, pair<int,int>> pos_dict; // 방향 char - 업데이트 좌표 dictionary
    pos_dict['U'] = {-1, 0};
    pos_dict['D'] = {1, 0};
    pos_dict['L'] = {0, -1};
    pos_dict['R'] = {0, 1};
    unordered_map<char, int> dir_dict; // 방향 char - 방향 index(passed에 넣을 용도)
    dir_dict['U'] = 0;
    dir_dict['R'] = 1;
    dir_dict['D'] = 2;
    dir_dict['L'] = 3;
    
    // 벽에 막힌 위치는 passed를 true로 채움
    for (int j = 0; j < LEN; j++) passed[0][j][dir_dict['U']] = true;
    for (int i = 0; i < LEN; i++) {
        passed[i][0][dir_dict['L']] = true;
        passed[i][LEN - 1][dir_dict['R']] = true;
    }
    for (int j = 0; j < LEN; j++) passed[LEN-1][j][dir_dict['D']] = true;
    
    // 시뮬레이션 (새로운 좌표는 0~10 범위를 가짐)
    int cur_y = 5;
    int cur_x = 5;
    int new_y;
    int new_x;
    for (char c: dirs) {
        new_y = cur_y + pos_dict[c].first;
        new_x = cur_x + pos_dict[c].second;
        if (new_y >= 0 && new_y < LEN && new_x >= 0 && new_x < LEN) {
            if (!passed[cur_y][cur_x][dir_dict[c]]) {
                passed[cur_y][cur_x][dir_dict[c]] = true;
                passed[new_y][new_x][(2 + dir_dict[c]) % 4] = true;
                answer++;
            }
            cur_y = new_y;
            cur_x = new_x;
        }
    }
    return answer;
}