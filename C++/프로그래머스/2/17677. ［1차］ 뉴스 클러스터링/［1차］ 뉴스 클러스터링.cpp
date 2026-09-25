#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool check(string inp) { // 넣어도 되는 string인지 확인
    for (char item : inp) {
        if (!((item >= 'a' && item <= 'z') || (item >= 'A' && item <= 'Z'))) return false;
    }
    return true;
}

int solution(string str1, string str2) {
    int answer = 0;
    
    // string 소문자 영어로 변환
    for (char &c : str1) c = tolower(c);
    for (char &c : str2) c = tolower(c);
    // cout << str1 << '\n' << str2;
    
    // dict에 저장
    unordered_map<string, pair<int,int>> dict;
    int n1 = str1.size();
    int n2 = str2.size();
    string temp;
    for (int i = 0; i < n1 - 1; i++) {
        temp = str1.substr(i, 2);
        if (!check(temp)) continue;
        else if (dict.find(temp) != dict.end()) {
            dict[temp].first++;
        }
        else {
            dict[temp] = {1, 0};
        }
    }
    for (int i = 0; i < n2 - 1; i++) {
        temp = str2.substr(i, 2);
        if (!check(temp)) continue;
        else if (dict.find(temp) != dict.end()) {
            dict[temp].second++;
        }
        else {
            dict[temp] = {0, 1};
        }
    }
    
    // dict를 순회하며 교집합/합집합 계산
    int up = 0;
    int down = 0;
    for (const auto &pair : dict) {
        // cout << pair.first << ' ' << pair.second.first << ' ' << pair.second.second << '\n';
        up += min(pair.second.first, pair.second.second);
        down += max(pair.second.first, pair.second.second);
    }
    
    if (down == 0) return 65536;
    
    double res = double(65536 * up) / double(down);
    answer = res;
    return answer;
}