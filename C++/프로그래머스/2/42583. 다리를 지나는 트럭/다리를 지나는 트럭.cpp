#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // 변수 설정
    int time_step = 0; // step(answer을 대체함)
    queue<int> que; // 현재 위치의 트럭 무게를 저장하는 queue
    int cursum = 0; // 현재 다리의 최종 무게
    int n = truck_weights.size(); // 트럭 개수
    int cur_out = 0; // 현재 빠져나온 트럭 개수
    
    // 초기 다리 설정
    for (int i = 0; i < bridge_length; i++) que.push(0);
    
    // 시뮬레이션
    while (true) {
        time_step++;
        
        // 우선 앞에 있는 것 부터 빼기
        cursum -= que.front();
        if (que.front() != 0) cur_out++;
        if (cur_out == n) break;
        que.pop();
        
        // cursum + 다음 트럭의 무게를 버틸 수 있으면 입력
        if (!truck_weights.empty() && truck_weights[0] + cursum <= weight) {
            cursum += truck_weights[0];
            que.push(truck_weights[0]);
            truck_weights.erase(truck_weights.begin());
        }
        else { // 버티지 못하면 0 입력
            que.push(0);
        }
        
        
        
    }
    
    return time_step;
}