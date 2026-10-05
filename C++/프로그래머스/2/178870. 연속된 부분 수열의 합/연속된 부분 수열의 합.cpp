#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    // 변수 설장
    vector<int> answer;
    long long target = k; // 목표 값
    int from = 0; // 시작 인덱스
    int to = 0; // 끝 인덱스
    int n = sequence.size(); // 크기
    queue<int> que; // 슬라이딩 윈도우
    long long cursum = 0;
    int len = 0;
    
    // 슬라이딩 윈도우 사용
    for (int i = 0; i < n; i++) {
        // 하나씩 queue에 넣음
        que.push(sequence[i]);
        cursum += sequence[i];
        to = i;
        
        // cursum이 target보다 크면 계속해서 슬라이딩 윈도우에서 하나씩 빼내기
        while (cursum > target) {
            long long temp = que.front();
            que.pop();
            cursum -= temp;
            from++;
        }
        
        // 만약 cursum이 target과 같다면 answer 업데이트
        if (cursum == target && (answer.empty() || len > (to - from + 1))) {
            answer.clear();
            answer.push_back(from);
            answer.push_back(to);
            len = to - from + 1;
        }
    }
    
    return answer;
}