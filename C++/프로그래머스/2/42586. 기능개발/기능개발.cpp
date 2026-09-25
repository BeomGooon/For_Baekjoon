#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer, req_days;
    int n = progresses.size(); // 작업 갯수
    
    // 작업별 필요한 날짜수 저장
    for (int i = 0; i < n; i++) {
        req_days.push_back((99 - progresses[i] + speeds[i]) / speeds[i]);
    }
    
    // 순차로 돌면서 최대 크기 갱신 및 갱신 사이 인덱스 차이 계산
    int local_max = req_days[0];
    int local_index = 0;
    for (int i = 0; i < n; i++) {
        if (req_days[i] > local_max) {
            local_max = req_days[i];
            answer.push_back(i-local_index);
            local_index = i;
        }
    }
    answer.push_back(n - local_index);
    
    return answer;
}