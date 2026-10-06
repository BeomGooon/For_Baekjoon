#include <string>
#include <cmath>
using namespace std;

// x, r: 행 / y, c: 열 (문제와 같은 이름)
string solution(int n, int m, int x, int y, int r, int c, int k) {
    int dist = abs(x - r) + abs(y - c);
    if (dist > k || (k - dist) % 2 == 1) return "impossible";

    // 사전순: d, l, r, u
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, -1, 1, 0};
    const char ch[4] = {'d', 'l', 'r', 'u'};

    string answer;
    while (k--) {   // k: 이번 걸음 이후 남은 걸음 수
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;   // 격자 밖
            if (abs(nx - r) + abs(ny - c) > k) continue;          // 도착 불가
            x = nx; y = ny;
            answer += ch[i];
            break;   // 가장 앞선 방향 하나만
        }
    }
    return answer;
}