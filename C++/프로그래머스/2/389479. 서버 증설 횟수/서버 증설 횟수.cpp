#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> players, int m, int k) {
    // 변수 및 초기화
    int answer = 0;
    int cur_capacity = m - 1; // 현재 수용가능한 인원
    queue<int> que; // 증설된 서버가 끝나는 시간을 입력 (ex. 5시에 증설된 서버는 5 + k - 1을 입력)
    
    for (int i = 0; i < 24; i++) {
        // queue 먼저 비우기
        while (!que.empty() && que.front() < i) {
            cur_capacity -= m;
            que.pop();
        }
        
        // 필요한 만큼 증설
        int cur_player = players[i];
        int add_num = max((cur_player - cur_capacity + m - 1) / m, 0); // 증설해야 하는 서버 수
        for (int j = 0; j < add_num; j++) {
            que.push(i + k - 1);
            cur_capacity += m;
            answer++;
        }
    }
    
    return answer;
}