#include <string>
#include <vector>
using namespace std;

bool check(const string& s, int start, int end) {
    if (start == end) return true;
    int mid = (start + end) / 2;
    if (s[mid] == '0') {
        // 더미 노드: 서브트리 전체가 0이어야 함
        for (int i = start; i <= end; i++)
            if (s[i] == '1') return false;
        return true;
    }
    return check(s, start, mid - 1) && check(s, mid + 1, end);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (long long num : numbers) {
        string bin = "";
        while (num > 0) { bin = char('0' + num % 2) + bin; num /= 2; }

        int full = 1;                          // 1, 3, 7, 15, 31, 63
        while (full < (int)bin.size()) full = full * 2 + 1;
        bin = string(full - bin.size(), '0') + bin;   // 앞을 0으로 채움

        answer.push_back(check(bin, 0, full - 1) ? 1 : 0);
    }
    return answer;
}