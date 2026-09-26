#include <string>
#include <vector>
#include <queue>

using namespace std;

// visited array, 결과값 array
bool visited[1000001];
int result[1000001];

int solution(int x, int y, int n) {
    int answer = 0;
    queue<pair<int, int>> que; // {실제 값, 변환 횟수}
    
    // visited, 결과값 array 초기화
    fill(visited, visited + 1000000, false);
    fill(result, result + 1000000, -1);
    
    // queue에 처음 값(x) 추가
    que.push({x, 0});
    
    // BFS 알고리즘 사용;
    while (!que.empty()) {
        int item = que.front().first;
        int trans_num = que.front().second;
        que.pop();
        
        // array 업데이트
        result[item] = trans_num;
        
        // 다음 값 넣기
        vector<int> temp;
        temp.push_back(item + n);
        temp.push_back(item * 2);
        temp.push_back(item * 3);
        
        // 조건 확인 후 que에 넣기
        for (int next : temp) {
            if (!visited[next] && next <= y) {
                visited[next] = true;
                que.push({next, trans_num + 1});
            }
        }
        
        temp.clear();
    }
    
    answer = result[y];
    return answer;
}