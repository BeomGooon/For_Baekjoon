#include <string>
#include <vector>
#include <iostream>

using namespace std;

// DFA 사용
// 0: 초기 상태, 1: 1을 읽은 상태, 2: 11 읽은 상태, 3: 110 찾은 상태
vector<vector<int>> next_state = {{0, 1}, {0, 2}, {3, 2}, {0, 1}};



vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for (string cur_str : s) {
        vector<char> cur_string;
        int num = 0;
        
        for (char item : cur_str) {
            cur_string.push_back(item);
            int n = cur_string.size();
            
            while (n >= 3 && cur_string[n-1] == '0' && cur_string[n-2] == '1' && cur_string[n-3] == '1') {
                cur_string.pop_back();
                cur_string.pop_back();
                cur_string.pop_back();
                n = cur_string.size();
                num++;
            }
        }
        
        string cur_string_str = "";
        for (char item : cur_string) cur_string_str += item;
        
        int last_zero = cur_string.size() - 1;
        while (last_zero >= 0 && cur_string[last_zero] == '1') last_zero--;
        
        // cout << last_zero << ' ' << cur_string.size() - last_zero - 1 << ' ' << cur_string_str << '\n';
        
        string temp_answer = "";
        if (last_zero >= 0) temp_answer = cur_string_str.substr(0, last_zero+1);
        for (int i = 0; i < num; i++) temp_answer += "110";
        if (last_zero + 1 < cur_string.size()) temp_answer += cur_string_str.substr(last_zero + 1, cur_string.size() - last_zero - 1);
        
        answer.push_back(temp_answer);
    }
    
    return answer;
}