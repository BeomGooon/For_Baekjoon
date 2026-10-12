#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> map;
    
    for (int i = 0; i < rows; i++) {
        map.push_back({});
        for (int j = 0; j < columns; j++) {
            map[i].push_back(i*columns + j + 1);
        }
    }
    
    for (vector<int> com : queries) {
        int sy = com[0] - 1;
        int sx = com[1] - 1;
        int ey = com[2] - 1;
        int ex = com[3] - 1;
        
        int remain = map[sy][sx];
        int output = remain;
        for (int y = sy; y < ey; y++) {
            map[y][sx] = map[y+1][sx];
            if (map[y][sx] < output) output = map[y][sx];
        }
        for (int x = sx; x < ex; x++) {
            map[ey][x] = map[ey][x+1];
            if (map[ey][x] < output) output = map[ey][x];
        }
        for (int y = ey; y > sy; y--) {
            map[y][ex] = map[y-1][ex];
            if (map[y][ex] < output) output = map[y][ex];
        }
        for (int x = ex; x > sx; x--) {
            map[sy][x] = map[sy][x-1];
            if (map[sy][x] < output) output = map[sy][x];
        }
        map[sy][sx+1] = remain;
        answer.push_back(output);
    }
    
    /* 디버그용 출력
    for (vector<int> &lis : map) {
        for (int item : lis) cout << item << ' ';
        cout << '\n';
    } 
    */
    return answer;
}