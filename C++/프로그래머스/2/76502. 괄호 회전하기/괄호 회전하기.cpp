#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <iostream>

using namespace std;

bool check(deque<char> dq) {
    stack<char> par_stack;
    while (!dq.empty()) {
        char temp = dq.front();
        dq.pop_front();
        if (par_stack.empty() || temp == '(' || temp == '{' || temp == '[') { // 그냥 추가
            par_stack.push(temp);
        }
        else if (temp - par_stack.top() == 1 || temp - par_stack.top() == 2) { // 맞는 짝
            par_stack.pop();
        }
        else { // 틀림
            return false;
        }
    }
    return (par_stack.empty());
}

int solution(string s) {
    int answer = 0;
    int n = s.size();
    deque<char> dq;
    for (int i = 0; i < n; i++) {
        dq.push_back(s[i]);
    }
    for (int i = 0; i < n; i++) {
        // cout << i << ' ' << dq.front() << '\n';
        if (check(dq)) {
            answer++;
            // cout << "found\n";
        }
        char temp = dq.front();
        dq.push_back(temp);
        dq.pop_front();
    }
    return answer;
}