#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    priority_queue<int> pq;
    int n = citations.size();
    
    // pq에 저장
    for (int i = 0; i < n; i++) {
        pq.push(citations[i]);
    }
    
    // 현재까지 읽은 개수와 방금 읽은 숫자를 비교
    // 방금 읽은 숫자가 개수보다 작거나 같으면 그게 답
    while (!pq.empty()) {
        int temp = pq.top();
        pq.pop();
        answer++;
        if (temp <= answer) {
            return max(temp, answer - 1);
        }
    }
    return answer;
}