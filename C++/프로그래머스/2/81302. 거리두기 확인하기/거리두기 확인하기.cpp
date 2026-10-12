#include <string>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int,int>> next_pos = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

vector<int> solution(vector<vector<string>> places) {
    int N = 5;
    vector<int> answer;
    
    for (vector<string> &map : places) {
        int output = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 'P') {
                    queue<vector<int>> que;
                    que.push({i,j, 0});
                    
                    while (!que.empty()) {
                        int cur_y = que.front()[0];
                        int cur_x = que.front()[1];
                        int cur_dist = que.front()[2];
                        que.pop();
                        
                        if (cur_dist < 2) {
                            for (int dir = 0; dir < 4; dir++) {
                                int next_y = cur_y + next_pos[dir].first;
                                int next_x = cur_x + next_pos[dir].second;
                                if (next_y >= 0 && next_y < N && next_x >= 0 && next_x < N && map[next_y][next_x] != 'X') {
                                    if (!(next_y == i && next_x == j) && map[next_y][next_x] == 'P') {
                                        output = 0;
                                        i = N;
                                        j = N;
                                    }
                                    else {
                                        que.push({next_y, next_x, cur_dist + 1});
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        answer.push_back(output);
    }
    return answer;
}