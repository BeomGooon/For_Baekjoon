#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 오른쪽에서 가장 가까운 0을 찾아 1로 바꿈
// 그 후, 1로 바꿨던 위치 바로 오른쪽의 1을 0으로 바꿈
long long step(long long inp) {
    long long temp = 0x01;
    while (temp & inp) temp <<= 1;
    inp = (inp | temp);
    
    temp >>= 1;
    inp = (inp ^ temp);
    return inp;
}


vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (long long item : numbers) {
        answer.push_back(step(item));
    }
    return answer;
}