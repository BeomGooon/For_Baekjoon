#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int SIZE;
const int PILLAR = 1;
const int BOE = 2;

pair<int,int> yx_to_xy(const pair<int,int> &inp) {
    pair<int,int> output = {inp.second, SIZE - inp.first};
    return output;
}

pair<int,int> xy_to_yx(const pair<int,int> &inp) {
    pair<int,int> output = {SIZE - inp.second, inp.first};
    return output;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    // 변수 및 초기화
    SIZE = n;
    vector<vector<int>> answer; // 현재 설치된 기둥/보 정보 (주의: 입력 형식은 build_frame을 따라감)
    vector<vector<int>> map; // 0: 비어있음, 1: 기둥, 2: 보, 3: 둘 다
    for (int i = 0; i <= SIZE; i++) {
        map.push_back({});
        for (int j = 0; j <= SIZE; j++) map[i].push_back(0);
    }
    
    // build_frame 하나씩 읽기
    for (vector<int> &command : build_frame) {
        int ori_x = command[0];
        int ori_y = command[1];
        int what = command[2] + 1; // map에 저장할 기둥/보 값은 받은거 + 1
        int how = command[3];
        pair<int,int> converted_pos = xy_to_yx({ori_x, ori_y});
        int con_y = converted_pos.first;
        int con_x = converted_pos.second;
        
        if (how == 0) { // 삭제
            bool flag = true; // 삭제해도 되는지 확인
            
            // 삭제해도 되는지 확인
            if (what == PILLAR) {
                // 기둥 삭제하면 안되는 조건
                // 1. 자기 기준 오른쪽/왼쪽 위 보가 양 옆에 보도 없고 다른 기둥도 없을 때
                // 2. 자기 기준 오른쪽/왼쪽 위 보가 없는데 위에 기둥이 있을 때
                if (map[con_y-1][con_x] >= 2 && (((con_x == 0 || map[con_y-1][con_x-1] < BOE) || (con_x == SIZE - 1 || map[con_y-1][con_x+1] < BOE)) && map[con_y][con_x+1] % 2 != PILLAR)) flag = false;
                if (con_x > 0 && map[con_y-1][con_x-1] >= 2 && (((con_x == 1 || map[con_y-1][con_x-2] < BOE) || (con_x == SIZE || map[con_y-1][con_x] < BOE)) && map[con_y][con_x-1] % 2 != PILLAR)) flag = false;
                if ((con_x == 0 || map[con_y-1][con_x-1] < BOE) && map[con_y-1][con_x] < BOE && map[con_y-1][con_x] % 2 == PILLAR) flag = false;
            }
            else {
                // 보 삭제하면 안되는 조건
                // 1. 자기와 근접한 보들이 기둥이 없을때
                // 2. 자기 위 또는 오른쪽 위 기둥이 있는데 해당 위치 밑에 기둥이 없고 보도 없을 때
                if (con_x > 0 && map[con_y][con_x-1] >= BOE && map[con_y+1][con_x] % 2 != PILLAR && map[con_y+1][con_x-1] % 2 != PILLAR) flag = false;
                if (con_x < SIZE - 1 && map[con_y][con_x+1] >= BOE && map[con_y+1][con_x+1] % 2 != PILLAR && map[con_y+1][con_x+2] % 2 != PILLAR) flag = false;
                if (map[con_y][con_x] % 2 == PILLAR && map[con_y+1][con_x] % 2 != PILLAR && (con_x == 0 || map[con_y][con_x-1] < BOE)) flag = false;
                if (map[con_y][con_x+1] % 2 == PILLAR && map[con_y+1][con_x+1] % 2 != PILLAR && (con_x == SIZE - 1 || map[con_y][con_x+1] < BOE)) flag = false;
            }
            
            if (!flag) continue;
            
            map[con_y][con_x] -= what; // 없는 구조물을 삭제하는 경우는 없기 때문
            for (int ind = 0; ind < answer.size(); ind++) {
                if (ori_x == answer[ind][0] && ori_y == answer[ind][1] && what - 1 == answer[ind][2]) {
                    answer.erase(answer.begin() + ind);
                    break;
                }
            }
        }
        else { // 설치
            if (what == PILLAR) { // 기둥 설치
                // 설치 가능
                if (con_y == SIZE || (map[con_y+1][con_x] % 2) == 1 || map[con_y][con_x] == 2 || (con_x > 0 && map[con_y][con_x-1] >= 2)) {
                    map[con_y][con_x] += PILLAR;
                    answer.push_back({ori_x, ori_y, what - 1});
                }
            }
            else { // 보 설치
                // 설치 가능
                if ((con_x < SIZE && (map[con_y+1][con_x] % 2 == PILLAR || map[con_y+1][con_x+1] % 2 == PILLAR)) || (con_x > 0 && con_x < SIZE - 1 && map[con_y][con_x-1] >= 2 && map[con_y][con_x+1] >= 2)) {
                    map[con_y][con_x] += BOE;
                    answer.push_back({ori_x, ori_y, what - 1});
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}