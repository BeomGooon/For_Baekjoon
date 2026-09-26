#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// 문자열 - 인덱스 쌍의 dictionary
unordered_map<string, int> dict;
int dict_num = 26;

// LZW를 구현한 함수
pair<int,int> lzw(string inp) {
    int n = inp.size();
    int output;
    for (int i = 1; i <= n; i++) {
        string temp_str = inp.substr(0, i);
        if (dict.find(temp_str) == dict.end()) {
            dict_num++;
            dict[temp_str] = dict_num;
            return {output, i - 1};
        }
        else {
            output = dict[temp_str];
        }
    }
    return {output, n};
}

vector<int> solution(string msg) {
    vector<int> answer;
    int n = msg.size();
    
    // dictionary 채우기
    for (int i = 0; i < 26; i++) {
        string temp = "";
        temp += char('A' + i);
        dict[temp] = i + 1;
    }
    
    // lzw 알고리즘 실행
    for (int i = 0; i < n; i++) {
        string temp = msg.substr(i, n - i);
        pair<int,int> temp_pair = lzw(temp);
        answer.push_back(temp_pair.first);
        i += (temp_pair.second - 1);
    }
    
    /* 디버깅용 출력 코드
    for (const auto &pair : dict) {
        cout << pair.first << ' ' << pair.second << '\n';
    }
    */
    
    return answer;
}