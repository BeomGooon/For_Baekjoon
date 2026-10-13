#include <vector>
#include <iostream>

using namespace std;

const int MOD = 20170805;
const int RIGHT = 0;
const int DOWN = 1;
const int LEFT = 2;
const int UP = 3;
vector<pair<int,int>> next_pos = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// 0 <= dist = y + x < m + n - 1
int solution(int row_num, int col_num, vector<vector<int>> city_map) {
    // 변수 및 초기화
    int answer = 0;
    vector<vector<vector<int>>> dist_map; // [y][x][방향]으로 갈 수 있는 경우의 수
    for (int i = 0; i < row_num; i++) {
        dist_map.push_back({});
        for (int j = 0; j < col_num; j++) {
            dist_map[i].push_back({});
            for (int k = 0; k < 2; k++) dist_map[i][j].push_back(0);
        }
    }
    dist_map[0][0][0] = 1;
    dist_map[0][0][1] = 1;
    
    
    for (int dist = 1; dist < row_num + col_num - 1; dist++) {
        for (int y = 0; y < row_num; y++) {
            int x = dist - y;
            if (x >= 0 && x < col_num && city_map[y][x] != 1) {
                for (int dir = 0; dir < 2; dir++) {
                    int before_y = y + next_pos[dir + 2].first;
                    int before_x = x + next_pos[dir + 2].second;
                    if (before_y >= 0 && before_x >= 0) {
                        if (city_map[y][x] == 2) {
                            dist_map[y][x][dir] += dist_map[before_y][before_x][dir];
                        }
                        else {
                            dist_map[y][x][0] += dist_map[before_y][before_x][dir];
                            dist_map[y][x][1] += dist_map[before_y][before_x][dir];
                        }
                    }
                }
                dist_map[y][x][0] %= MOD;
                dist_map[y][x][1] %= MOD;
            }
        }
    }
    
    answer = dist_map[row_num-1][col_num-1][0];
    
    return answer;
}