#include <string>
#include <vector>

using namespace std;

long long temp[2];

int solution(int n) {
    long long answer = 0;
    temp[0] = 1;
    temp[1] = 2;
    
    // n이 1 또는 2이면 바로 출력
    if (n < 3) return n;
    
    // n이 3 이상이면 (n-2)횟수만큼 업데이트 후 출력
    for (int i = 2; i < n; i++) {
        answer = (temp[0] + temp[1]) % 1000000007;
        temp[0] = temp[1];
        temp[1] = answer;
    }
    
    return answer;
}

/*
1: 1
2: 2
3: 3
4: 5
5: 8
6: 13
*/