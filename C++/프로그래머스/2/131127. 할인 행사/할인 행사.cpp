#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

bool match(vector<string> &want, vector<int> &number, unordered_map<string,int> &dict) {
    int want_size = want.size();
    for (int i = 0; i < want_size; i++) {
        string str_temp = want[i];
        int num_temp = number[i];
        if (dict[str_temp] != num_temp) return false;
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> dict;
    int n = discount.size();
    queue<string> que;
    
    string temp; // 현재 읽은 물품 이름
    for (int i = 0; i < 10; i++) {
        temp = discount[i];
        if (dict.find(temp) != dict.end()) { // 이미 존재 => +1
            dict[temp]++;
        }
        else { // 처음 만남 => 추가
            dict[temp] = 1;
        }
        que.push(temp);
    }
    if (match(want, number, dict)) { // 현재 매치가 맞을 때 => answer++;
        answer++;
    }
    for (int i = 10; i < n; i++) {
        // 기존의 item queue에서 제거
        temp = que.front();
        que.pop();
        dict[temp]--;
        
        // 새로운 item 추가
        temp = discount[i];
        if (dict.find(temp) != dict.end()) { // 이미 존재 => +1
            dict[temp]++;
        }
        else { // 처음 만남 => 추가
            dict[temp] = 1;
        }
        que.push(temp);
        
        if (match(want, number, dict)) { // 현재 매치가 맞을 때 => answer++;
            answer++;
        }
    }
    
    return answer;
}