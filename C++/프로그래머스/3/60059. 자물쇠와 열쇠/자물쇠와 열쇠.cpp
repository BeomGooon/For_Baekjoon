#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 상대적인 위치 변화를 반시계방향으로 돌린 모든 경우의 수를 return
vector<vector<int>> all_dir(const vector<int> &inp) {
    vector<vector<int>> output;
    output.push_back(inp);
    output.push_back({-inp[1], inp[0]});
    output.push_back({-inp[0], -inp[1]});
    output.push_back({inp[1], -inp[0]});
    return output;
}

// lock과 key를 대조해 맞는지 확인
// 변수 설명
// map: lock을 포함한 3n x 3n 지도
// rel_pos: 특정 key의 점을 기준으로 나머지 점들의 상대 위치를 저장한 2중 리스트
// y: 특정 key의 점의 y 좌표
// x: 특정 key의 점의 x 좌표
// n: lock 한 변의 크기
// target: lock 속 비어있는 공간 개수
bool match(vector<vector<bool>> &map, vector<vector<int>> &rel_pos, int y, int x, int n, int target) {
    bool flags[4] = {true, true, true, true};
    int cur_matched[4] = {1, 1, 1, 1}; // 현재까지 푼 위치
    for (vector<int> pair : rel_pos) { // 모든 연결된 다른 점들 확인
        vector<vector<int>> temp = all_dir(pair);
        for (int i = 0; i < 4; i++) { // 모든 방향 확인
            vector<int> item = temp[i];
            int ny = y + item[0];
            int nx = x + item[1];
            if (!flags[i]) continue; // 고려할 필요 없음
            if (map[ny][nx]) { // 특정 방향에 이미 lock에 존재하면
                flags[i] = false;
            } 
            else if (ny < 2 * n && ny >= n && nx < 2 * n && nx >= n) { // 유효 공간을 공략한 경우
                cur_matched[i]++;
            }
        }
    }
    
    for (int i = 0; i < 4; i++) {
        if (flags[i] && cur_matched[i] == target) return true;
    }
    return false;
}

// key의 모든 점의 좌표에 대한 데이터를 읽고 모든 상대 조합들 계산
vector<vector<vector<int>>> all_poses(vector<vector<int>> &key) {
    int num = key.size(); // key의 점들의 개수
    vector<vector<vector<int>>> output;
    for (int i = 0; i < num; i++) {
        vector<vector<int>> temp;
        for (int j = 0; j < num; j++) {
            if (i==j) continue;
            temp.push_back({key[j][0] - key[i][0], key[j][1] - key[i][1]});
        }
        output.push_back(temp);
    }
    return output;
}

// key 지도를 읽고 유효한 좌표들을 계산
vector<vector<int>> positions(vector<vector<int>> &map) {
    int m = map.size();
    vector<vector<int>> output;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j]) output.push_back({i, j});
        }
    }
    return output;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    // 변수 및 초기화
    int n = lock.size();
    int m = key.size();
    int st_y;
    int st_x;
    vector<vector<int>> key_positions = positions(key); // key의 좌표들만을 저장
    vector<vector<vector<int>>> rel_positions = all_poses(key_positions); // 모든 key 점들에 대해 상대 좌표들 계산
    vector<vector<bool>> extended_map; // 3n x 3n의 확장된 맵
    int key_point = key_positions.size(); // key 속 유효한 점들의 개수
    int lock_point = 0; // lock 속 유효한 점들의 개수
    
    // 확장된 맵 초기화
    for (int i = 0; i < 3 * n; i++) {
        vector<bool> temp;
        for (int j = 0; j < 3 * n; j++) {
            if (i >= n && i < 2 * n && j >= n && j < 2 * n) {
                temp.push_back(lock[i-n][j-n]);
                if (!lock[i-n][j-n]) {
                    st_y = i;
                    st_x = j;
                    lock_point++;
                }
            }
            else temp.push_back(false);
        }
        extended_map.push_back(temp);
    }
    
    if (lock_point == 0) return true;
    
    // lock 내 비어있는 점 하나를 고른 후, 해당 점과 key의 특정 좌표를 맞춘 후 match가 되는지 확인
    for (int i = 0; i < key_point; i++) {
        if (match(extended_map, rel_positions[i], st_y, st_x, n, lock_point)) return true;
    }
    
    /* 디버깅용
    cout << "rel_positions: \n";
    for (vector<vector<int>> matrix : rel_positions) {
        for (vector<int> lis : matrix) {
            cout << '{';
            for (int item : lis) {
                cout << item << ' ';
            }
            cout << "}, ";
        }
        cout << '\n';
    }
    cout << "\nextended_map: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << extended_map[i+n][j+n];
        }
        cout << '\n';
    }
    cout << "\nst_y: " << st_y << ", st_x: " << st_x << ", n: " << n << ", lock_point: " << lock_point;
    vector<vector<int>> temp_all_dir = all_dir({1, 2});
    cout << "\ntemp_all_dir: of {1,2}";
    for (vector<int> lis : temp_all_dir) {
        cout << "\n{";
        for (int item : lis) {
            cout << item << ' ';
        }
        cout << "}";
    }
    */
    
    return false;
}