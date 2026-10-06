#include <string>
#include <vector>

using namespace std;

char three_to_124[3] = {'1', '2', '4'};

string solution(int n) {
    // 변수 및 초기화
    string answer = "";
    vector<int> three;
    
    // 3진법으로 변환
    while (n) {
        n--;
        if (n == 0) three.push_back(0);
        else three.push_back(n%3);
        n /= 3;
    }
    
    // 124나라 숫자로 역산
    // 주의할 점: 순서를 반대로 해야 함
    for (int item : three) {
        answer = three_to_124[item] + answer;
    }
    
    return answer;
}