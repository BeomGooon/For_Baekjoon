#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

bool prime_list[10000000] = {false, }; // 소수가 false고 소수가 아니면 true임
const int max_num = 10000000;
unordered_map<int, bool> dict;

// string을 int로 바꾸는 함수
int str_to_int(string inp) {
    int output = 0;
    for (char item : inp) {
        output = (item - '0') + output * 10;
    }
    return output;
}

void prime_set(bool list[]) {
    list[0] = true;
    list[1] = true;
    for (int i = 2; i < max_num; i++) {
        if (!prime_list[i]) {
            int temp = i * 2;
            while (temp < max_num) {
                prime_list[temp] = true;
                temp += i;
            }
        }
    }
}

// string 속 각 인덱스의 새로운 순서를 저장하는 함수
void dfs(string cur, vector<char> availables) {
    vector<char> temp;
    int n = availables.size();
    for (int i = 0; i < n; i++) {
        // 하나를 골라 더한 값을 dict에 저장
        string temp_inp = cur + availables[i];
        dict[str_to_int(temp_inp)] = true;
        
        // 재귀함수 호출
        temp = availables;
        temp.erase(temp.begin() + i);
        dfs(temp_inp, temp);
    }
    return;
}

int solution(string numbers) {
    int answer = 0;
    
    // 소수 리스트 업데이트
    prime_set(prime_list);
    
    string str = "";
    vector<char> inp_char;
    
    // inp_char에 숫자 하나씩 저장
    for (char item : numbers) {
        inp_char.push_back(item);
    }
    
    // dfs 호출 => dict에 저장
    dfs(str, inp_char);
    
    // 하나씩 꺼내서 소수인지 확인
    for (const auto &pair : dict) {
        if (!prime_list[pair.first]) answer++;
    }
    
    return answer;
}