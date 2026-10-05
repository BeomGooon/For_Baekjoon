#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    // 변수 설정
    string answer = "";
    int start = 0; // 시작 지점
    int erase_left = k; // 남은 지울 수 있는 횟수
    int n = number.size(); // string 길이
    
    // start ~ start + erase_left 인덱스 중 가장 높은 수 선택
    // 그 전까지를 모두 지운 후 start를 그 다음 인덱스로 바꾸고 erase_left를 지운 갯수만큼 차감
    while (erase_left && start < n - erase_left) {
        int cur_max = -1;
        int cur_ind = 0;
        
        // start ~ start + erase_left를 둘러보며 큰 수 찾기
        for (int i = 0; i <= erase_left; i++) {
            int cur_item = number[start + i] - '0';
            if (cur_max < cur_item) {
                cur_max = cur_item;
                cur_ind = i;
            }
        }
        
        // 큰 수만 answer에 추가하고 erase_left 차감, start를 그 다음 인덱스로 바꿈
        start += cur_ind + 1;
        erase_left -= cur_ind;
        answer += char(cur_max + '0');
    }
    
    // erase_left를 모두 소진한 경우 start부터 나머지를 모두 answer에 추가해야 함
    if (erase_left == 0) {
        answer += number.substr(start, n - start);
    }
    
    return answer;
}