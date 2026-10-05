#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> all_directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int solution(vector<string> maps) {
    // 변수 및 초기화
    int answer = -1;
    int temp_answer = 0;
    int row_num = maps.size();
    int col_num = maps[0].size();
    queue<vector<int>> que; // 현재 y축, x축, 이동시간 기록
    char target = 'L'; // 타겟 문자
    vector<vector<bool>> touched;
    vector<bool> temp_vec;
    for (int i = 0; i < row_num; i++) {
        for (int j = 0; j < col_num; j++) temp_vec.push_back(false);
        touched.push_back(temp_vec);
        temp_vec.clear();
    }
    
    // 훑어가며 시작 지점 확인
    for (int i = 0; i < maps.size(); i++) {
        bool flag = false;
        for (int j = 0; j < maps[0].size(); j++) {
            if (maps[i][j] == 'S') {
                touched[i][j] = true;
                que.push({i, j, 0});
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    
    for (int i = 0; i < 2; i++) {
        while (!que.empty()) {
            vector<int> temp = que.front();
            que.pop();

            // target(L 또는 E)를 만나면 마무리
            if (maps[temp[0]][temp[1]] == target) {
                if (target == 'L') { // 처음 target을 만남
                    temp_answer = temp[2];
                    target = 'E';
                }
                else { // 두 번째 target을 만남
                    answer = temp_answer + temp[2];
                }
                while (!que.empty()) que.pop();
                que.push({temp[0], temp[1], 0});
                break;
            }

            // 다음 좌표 추가
            for (pair<int,int> item : all_directions) {
                int ny = temp[0] + item.first;
                int nx = temp[1] + item.second;
                if (ny >= 0 && ny < row_num && nx >= 0 && nx < col_num && maps[ny][nx] != 'X' && !touched[ny][nx]) {
                    touched[ny][nx] = true;
                    que.push({ny, nx, temp[2] + 1});
                }
            }
        }
        for (int i = 0; i < row_num; i++) {
            for (int j = 0; j < col_num; j++) touched[i][j] = false;
        }
    }
    return answer;
}