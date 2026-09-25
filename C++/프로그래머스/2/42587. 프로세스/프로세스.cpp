#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int n = priorities.size();
    priority_queue<int> pq; // pq 하나씩 꺼내서 확인 용도
    queue<pair<int,int>> que; // {원래 인덱스, 우선순위} 형식의 queue
    
    // pq 및 queue에 프로세스 정보저장
    for (int i = 0; i < n; i++) {
        pq.push(priorities[i]);
        que.push({i, priorities[i]});
        // printf("%d %d\n", i, priorities[i]);
    }
    
    // 프로세스 하나씩 꺼내기
    int completed = 0;
    while (!pq.empty()) {
        int target_priority = pq.top();
        pq.pop();
        pair<int,int> temp = que.front();
        while (temp.second != target_priority) {
            que.push(temp);
            que.pop();
            temp = que.front();
        }
        completed++;
        if (location == temp.first) answer = completed;
        que.pop();
    }
    
    return answer;
}