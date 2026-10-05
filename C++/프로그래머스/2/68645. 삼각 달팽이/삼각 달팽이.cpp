#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(int n) {
    // 변수 초기화
    vector<vector<int>> map;
    vector<int> answer;
    for (int i = 0; i < n; i++) {
        map.push_back({});
        for (int j = 0; j <= i; j++) {
            map[i].push_back(0);
        }
    }
    
    // 반시계방향으로 진행
    int y = 0;
    int x = 0;
    int dir = 0;
    int dir_list[3][2] = {{1,0}, {0, 1}, {-1, -1}};
    queue<vector<int>> que; // y, x, dir, 저장할 수 순서대로 전달
    que.push({0,0,0,1});
    map[0][0] = 1;
    while (!que.empty()) {
        vector<int> item = que.front();
        que.pop();
        for (int i = 0; i < 2; i++) {
            int ny = dir_list[(item[2] + i) % 3][0] + item[0];
            int nx = dir_list[(item[2] + i) % 3][1] + item[1];
            if (ny >= 0 && ny < n && nx >= 0 && nx <= ny && map[ny][nx] == 0) {
                map[ny][nx] = item[3] + 1;
                que.push({ny, nx, (item[2] + i) % 3, item[3] + 1});
                break;
            }
        }
    }
    
    // answer에 추가
    for (vector<int> list : map) {
        for (int item : list) answer.push_back(item);
    }
    
    return answer;
}