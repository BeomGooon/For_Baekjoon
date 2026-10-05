#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int storey) {
    // 변수 설정 및 초기화
    int answer = 0x7fffffff;
    queue<pair<int, int>> que; // 현재 남은 숫자, 마법의 돌 소모 횟수
    que.push({storey, 0});
    
    // BFS
    while (!que.empty()) {
        pair<int,int> temp = que.front();
        que.pop();
        
        // 업데이트
        if (temp.first == 0 && answer > temp.second) answer = temp.second;
        else if (temp.first < 10) {
            int tem = temp.second + min(temp.first, 11 - temp.first);
            if (answer > tem) answer = tem;
        }
        
        if (temp.first > 9) {
            // 0으로 가던지 10으로 가던지 선택
            que.push({temp.first / 10, temp.second + (temp.first % 10)});
            que.push({temp.first / 10 + 1, temp.second + 10 - (temp.first % 10)});
        }
    }
    
    return answer;
}

/*
0 -> 0
1 -> 1
2 -> 2
3 -> 3
4 -> 4
5 -> 5
6 -> 4 + 1
7 -> 3 + 1
8 -> 2 + 1
9 -> 1 + 1
*/