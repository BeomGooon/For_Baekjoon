#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> op_list = {
    "+-*",
    "+*-",
    "-+*",
    "-*+",
    "*+-",
    "*-+"
};

long long str_to_long(string &inp) {
    long long output = 0;
    for (char item : inp) {
        output = (output * 10) + (item - '0');
    }
    return output;
}

void split(string &inp, vector<long long> &numbers, string &operands) {
    string temp = "";
    for (char item : inp) {
        if (item == '+' || item == '-' || item == '*') {
            numbers.push_back(str_to_long(temp));
            temp = "";
            operands += item;
        }
        else {
            temp += item;
        }
    }
    numbers.push_back(str_to_long(temp));
    return;
}

long long solution(string expression) {
    long long answer = 0;
    
    // 변수 넣기
    vector<long long> original_numbers;
    string operands;
    split(expression, original_numbers, operands);
    
    // 계산
    for (string sequence : op_list) {
        vector<long long> cur_numbers = original_numbers;
        string cur_ops = operands;
        long long output;
        for (int i = 0; i < 3; i++) {
            vector<long long> temp_numbers;
            string temp_ops = "";
            
            char cur_op = sequence[i];
            long long left = cur_numbers[0];
            for (int ind = 0; ind < cur_ops.size(); ind++) {
                long long right = cur_numbers[ind + 1];
                if (cur_op == cur_ops[ind]) {
                    if (cur_ops[ind] == '-') left -= right;
                    else if (cur_ops[ind] == '+') left += right;
                    else left *= right;
                }
                else {
                    temp_numbers.push_back(left);
                    temp_ops += cur_ops[ind];
                    left = right;
                }
            }
            temp_numbers.push_back(left);
            cur_numbers.clear();
            cur_numbers = temp_numbers;
            cur_ops = temp_ops;
        }
        output = cur_numbers[0];
        if (output < 0) output *= (-1);
        if (answer < output) answer = output;
    }
    
    
    return answer;
}