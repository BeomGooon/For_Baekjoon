#include <string>
#include <vector>
#include <queue>

using namespace std;


// 슬라이딩 윈도우 활용: queue1과 queue2를 순서대로 연결해 
int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    
    // 변수 설정
    int len = queue1.size(); // 초기 queue의 길이
    int from = 0; // 슬라이딩 윈도우의 시작 인덱스
    int to = 0; // 슬라이딩 윈도우의 마지막 인덱스
    queue<long long> que; // 슬라이딩 윈도우 큐
    long long target = 0; // 목표로 하는 sum. 전체 sum의 1/2
    long long cursum = 0; // 현재 슬라이딩 윈도우의 전체 합
    
    // target 계산
    for (int i = 0; i < len; i++) {
        target += queue1[i];
        target += queue2[i];
    }
    target /= 2;
    
    // 슬라이딩 윈도우 계산
    for (int i = 0; i < len; i++) {
        // queue1[i]를 큐에 집어넣음
        que.push(queue1[i]);
        cursum += queue1[i];
        to = i;
        
        // target보다 크면 작아질 때 까지 queue의 앞에서 지움
        while (cursum > target) {
            long long temp = que.front();
            que.pop();
            cursum -= temp;
            from++;
        }
        
        // 만약 현재 queue의 sum이 target과 같다면 뽑아야 하는 횟수 계산
        if (cursum == target) {
            int temp_answer = 0; // 현재 상황의 횟수
            
            // to가 마지막이라 앞에 것만 제거하면 됨
            if (to == len - 1) {
                temp_answer = from;
            }
            else { // to가 마지막이 아님 => to까지 queue2로 보내고 from 전까지 다시 queue1으로 보냄
                temp_answer += to + 1;
                temp_answer += from + len;
            }
            
            // answer에 저장
            if (answer == -1 || answer > temp_answer) answer = temp_answer;
        }
    }
    for (int i = 0; i < len; i++) {
        // queue2[i]를 큐에 집어넣음
        que.push(queue2[i]);
        cursum += queue2[i];
        to++;
        
        // target보다 크면 작아질 때까지 제거
        while (cursum > target) {
            long long temp = que.front();
            que.pop();
            cursum -= temp;
            from++;
        }
        
        // cursum이 target보다 같으면 answer 업데이트
        if (cursum == target) {
            int temp_answer = 0; // 임시 answer
            
            // from이 아직 queue1에 있는 경우 => queue2의 내용물을 queue1에, from 앞 내용물을 queue2에 보냄
            if (from < len) {
                temp_answer += (to - len + 1);
                temp_answer += from;
            }
            else {
                if (to == len * 2 - 1) { // to가 마지막인 경우: queue2의 from 앞 내용물만 queue1으로 옮기면 됨
                    temp_answer = from - len;
                }
                else { // to가 마지막이 아님: queue2의 to까지의 내용물을 queue1으로 보낸 뒤, queue1의 from 전까지의 내용물을 queue2로 다시 보냄
                    temp_answer += to - len + 1;
                    temp_answer += from;
                }
            }
            if (answer == -1 || answer > temp_answer) answer = temp_answer;
        }
    }
    
    return answer;
}