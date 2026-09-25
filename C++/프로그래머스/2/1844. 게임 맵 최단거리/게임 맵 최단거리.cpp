#include<vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps)
{
    int answer = -1;
    int row_num = maps.size();
    int col_num = maps[0].size();
    queue<vector<int>> que; // [y좌표, x좌표, 현재까지 이동 거리]
    
    vector<int> inp, outp;
    inp.push_back(0);
    inp.push_back(0);
    inp.push_back(1);
    que.push(inp);
    maps[0][0] = 0;
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (!que.empty()) {
        inp = que.front();
        if (inp[0] == row_num - 1 && inp[1] == col_num - 1) return inp[2];
        que.pop();
        for (int i = 0; i < 4; i++) {
            int next_y = inp[0] + directions[i][0];
            int next_x = inp[1] + directions[i][1];
            if (next_y >= 0 && next_y < row_num && next_x >= 0 && next_x < col_num && maps[next_y][next_x]) {
                maps[next_y][next_x] = 0;
                outp.push_back(next_y);
                outp.push_back(next_x);
                outp.push_back(inp[2]+1);
                que.push(outp);
                outp.clear();
            }
        }
    }
    
    return answer;
}