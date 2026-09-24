#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> dict;
    int clothes_num = clothes.size();
    int type_num = 0;
    
    // 각 type당 가지고 있는 의류의 개수를 dict에 저장
    for (int i = 0; i < clothes_num; i++) {
        string name = clothes[i][0];
        string type = clothes[i][1];
        if (dict.find(type) == dict.end()) { // 처음 보는 type
            dict[type] = 1;
            type_num++;
        }
        else {
            dict[type]++;
        }
    }
    
    for (const auto &pair : dict) {
        answer *= (pair.second+1);
        // cout << pair.second << '\n';
    }
    answer--;
    return answer;
}