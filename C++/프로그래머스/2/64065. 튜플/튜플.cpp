#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int n = s.size();
    
    // 전체 순회하면서 값 골라내기
    bool flag = false;
    s = s.substr(1, n-2);
    // cout << s;
    vector<int> temp_vec;
    int temp_num = 0;
    unordered_map<int, int> dict; // 각 숫자가 언제 처음으로 나왔는지 기록
    for (char &c : s) {
        if (!flag && c == '{') {
            flag = true;
        }
        if (flag) {
            if (c >= '0' && c <= '9') {
                temp_num = temp_num * 10 + (c - '0');
            }
            if (c == ',' || c == '}') {
                // cout << temp_num << " in\n";
                temp_vec.push_back(temp_num);
                temp_num = 0;
            }
            if (c == '}') {
                int n = temp_vec.size();
                for (int m : temp_vec) {
                    if (dict.find(m) == dict.end() || dict[m] > n) dict[m] = n;
                }
                flag = false;
                temp_vec.clear();
            }
        }
    }
    
    int result_map[500];
    int total_num = 0;
    for (const auto &pair : dict) {
        result_map[pair.second - 1] = pair.first;
        if (total_num < pair.second) total_num = pair.second;
    }
    
    for (int i = 0; i < total_num; i++) {
        answer.push_back(result_map[i]);
    }
    
    return answer;
}