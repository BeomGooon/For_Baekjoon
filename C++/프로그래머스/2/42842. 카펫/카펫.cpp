#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    long long total = brown + yellow;
    long long mul = floor(sqrt(total));
    int plus = (brown + 4) / 2;
    for (long long i = 1; i <= mul; i++) {
        if (total % i == 0) {
            long long j = total / i;
            if (i + j == plus) {
                answer.push_back(j);
                answer.push_back(i);
                return answer;
            }
        }
    }
    return answer;
}