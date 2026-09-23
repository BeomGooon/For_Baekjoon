#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int> pq2;
    
    for (int i = 0; i < people.size(); i++) {
        pq1.push(people[i]);
        pq2.push(people[i]);
    }
    
    int cur = 0; // 현재까지 탑승 완료한 사람들
    int total = people.size();
    int small = pq1.top();
    int big = pq2.top();
    pq1.pop();
    pq2.pop();
    while (cur < total) {
        if (small + big > limit) { // 큰 거 혼자 태우기
            answer++;
            cur++;
            big = pq2.top();
            pq2.pop();
        }
        else { // 둘이 같이 태우기
            answer++;
            cur += 2;
            small = pq1.top();
            big = pq2.top();
            pq1.pop();
            pq2.pop();
        }
    }
    return answer;
}