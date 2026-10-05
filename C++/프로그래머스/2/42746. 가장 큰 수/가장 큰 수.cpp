#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string int_to_str(int inp) {
    string output = "";
    if (inp == 0) return "0";
    while (inp) {
        output = char(inp % 10 + '0') + output;
        inp /= 10;
    }
    return output;
}

bool str_cmp(string &inp1, string &inp2) {
    return (inp1 + inp2 > inp2 + inp1);
}

string solution(vector<int> numbers) {
    vector<string> numbers_str;
    string answer = "";
    string before_answer = "";
    for (int item : numbers) {
        numbers_str.push_back(int_to_str(item));
    }
    sort(numbers_str.begin(), numbers_str.end(), str_cmp);
    for (string item : numbers_str) {
        before_answer += item;
    }
    
    bool flag = false; // 0이 아닌 문자를 처음으로 만나게 되면 true가 됨
    for (char item : before_answer) {
        if (!flag && item != '0') flag = true;
        if (flag) answer += item;
    }
    if (answer == "") answer = "0";
    return answer;
}