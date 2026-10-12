#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int,int>> next_pos = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int row_num = maps.size();
    int col_num = maps[0].size();
    vector<vector<bool>> touched;
    for (int i = 0; i < row_num; i++) {
        touched.push_back({});
        for (int j = 0; j < col_num; j++) touched[i].push_back(false);
    }
    
    for (int i = 0; i < row_num; i++) {
        for (int j = 0; j < col_num; j++) {
            if (maps[i][j] != 'X' && !touched[i][j]) {
                touched[i][j] = true;
                int output = 0;
                queue<vector<int>> que; // {y, x}
                que.push({i, j});
                while (!que.empty()) {
                    int cur_y = que.front()[0];
                    int cur_x = que.front()[1];
                    que.pop();
                    output += (maps[cur_y][cur_x] - '0');
                    for (int dir = 0; dir < 4; dir++) {
                        int next_y = cur_y + next_pos[dir].first;
                        int next_x = cur_x + next_pos[dir].second;
                        if (next_y >= 0 && next_y < row_num && next_x >= 0 && next_x < col_num && !touched[next_y][next_x] && maps[next_y][next_x] != 'X') {
                            touched[next_y][next_x] = true;
                            que.push({next_y, next_x});
                        }
                    }
                }
                answer.push_back(output);
            }
        }
    }
    
    if (answer.size() == 0) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    return answer;
}