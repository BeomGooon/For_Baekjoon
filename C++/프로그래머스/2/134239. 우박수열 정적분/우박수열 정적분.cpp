#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    int input_num = ranges.size();
    int n = 0;
    int cur = k;
    vector<double> integral;
    integral.push_back(0);
    while (cur != 1) {
        double area = cur;
        if (cur % 2) { // 홀수 => 곱하기 3 더하기 1
            cur = cur * 3 + 1;
        }
        else { // 짝수 => 나누기 2
            cur /= 2;
        }
        area = (area + cur) / 2;
        // cout << area << endl;
        integral.push_back(integral[n] + area);
        n++;
    }
    
    for (int i = 0; i < input_num; i++) {
        int from = ranges[i][0];
        int to = n + ranges[i][1];
        if (from <= to) {
            answer.push_back(integral[to] - integral[from]);
        }
        else {
            answer.push_back(-1);
        }
    }
    
    return answer;
}