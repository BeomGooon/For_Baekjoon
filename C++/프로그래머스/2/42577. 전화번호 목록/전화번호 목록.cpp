#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, bool> phone_dict[21];
    unordered_map<int, int> phone_len_dict;
    int n = phone_book.size();
    
    
    // 길이에 맞는 전화번호 dictionary 및 전화번호 길이 종류 dict
    for (int i = 0; i < n; i++) {
        string temp = phone_book[i];
        int temp_len = temp.size();
        phone_dict[temp_len][temp] = true;
        if (phone_len_dict.find(temp_len) == phone_len_dict.end()) {
            phone_len_dict[temp_len] = 1;
        }
        else {
            phone_len_dict[temp_len]++;
        }
    }
    
    // 모든 전화번호에 대해 확인 진행
    for (int i = 0; i < n; i++) {
        string temp = phone_book[i];
        int temp_len = temp.size();
        string sub_str = temp.substr(0, 1);
        for (int j = 1; j < temp_len; j++) {
            if (phone_len_dict.find(j) != phone_len_dict.end() && phone_dict[j].find(sub_str) != phone_dict[j].end()) {
                return false;
            }
            sub_str += temp[j];
        }
    }
    
    return answer;
}