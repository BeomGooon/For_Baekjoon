#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    queue<long long> que;
    if (n < 3) {
        return n;
    }
    
    que.push(1);
    que.push(2);
    for (int i = 2; i < n; i++) {
        long long temp = (que.front() + que.back()) % 1234567;
        que.pop();
        que.push(temp);
    }
    answer = que.back();
    return answer;
}