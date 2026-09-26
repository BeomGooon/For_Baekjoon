#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 현재 방법으로 할 때 고려할 사항: k진법으로 나눴을 때 overflow는 나오지 않는가

string int_to_str(int inp, int k) { // k 진법으로 바꾼 후 string으로 변환
    string output = "";
    while (inp) {
        output = char((inp % k) + '0') + output;
        inp /= k;
    }
    return output;
}

vector<long long> str_to_vec(string inp) { // string으로 바뀐 k진법 수를 0 단위로 나눠 long long으로 바꿈
    vector<long long> output;
    long long temp = 0;
    for (char item : inp) {
        if (item == '0') {
            if (temp != 0) {
                output.push_back(temp);
                temp = 0;
            }
        }
        else {
            long long item_long = item - '0';
            temp = (temp * 10) + item_long;
        }
    }
    if (temp != 0) output.push_back(temp);
    return output;
}

bool prime_check(long long inp) {
    if (inp < 2) return false;
    for (long long i = 2; i * i <= inp; i++) {
        if (inp % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string k_degree = int_to_str(n, k);
    vector<long long> sliced = str_to_vec(k_degree);
    
    // 확인용 출력 코드
    // cout << k_degree << '\n';
    // for (long long item : sliced) cout << item << '\n';
    
    // 최댓값 확인
    long long max_num = 0;
    for (long long item : sliced) {
        if (item > max_num) max_num = item;
    }
    
    for (long long item : sliced) {
        if (prime_check(item)) answer++;
    }
    
    return answer;
}