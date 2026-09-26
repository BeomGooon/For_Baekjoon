#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int item : scoville) {
        pq.push(item);
    }
    
    while (pq.top() < K) {
        int i1 = pq.top();
        pq.pop();
        if (pq.empty()) return -1;
        int i2 = pq.top();
        pq.pop();
        pq.push(i1 + i2 * 2);
        answer++;
    }
    
    return answer;
}