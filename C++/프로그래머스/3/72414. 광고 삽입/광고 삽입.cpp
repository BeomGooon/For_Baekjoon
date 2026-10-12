#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// HH:MM:SS 형태의 string을 초 단위로 바꿈
long long str_to_seconds(string &inp) {
    long long output = 0;
    long long mul = 3600;
    long long cur_num = 0;
    for (char item : inp) {
        if (item == ':') {
            output += mul * cur_num;
            mul /= 60;
            cur_num = 0;
        }
        else {
            cur_num = (cur_num * 10) + (item - '0');
        }
    }
    output += cur_num;
    return output;
}

string int_to_str(long long inp) {
    string output = "";
    while (inp) {
        output = (char)(inp % 10 + '0') + output;
        inp /= 10;
    }
    if (output.size() == 0) return "00";
    if (output.size() == 1) output = "0" + output;
    return output;
}

// 초 단위의 숫자를 다시 "HH:MM:SS"로 바꿈
string seconds_to_str(long long inp) {
    long long hour = inp / 3600;
    long long min = (inp % 3600) / 60;
    long long sec = inp % 60;
    
    string output = int_to_str(hour) + ":" + int_to_str(min) + ":" + int_to_str(sec);
    return output;
}

// log를 바탕으로 sliding window에 기록
void record(vector<long long> &window, string &inp) {
    long long start;
    long long end;
    
    string temp = "";
    for (char item : inp) {
        if (item == '-') {
            start = str_to_seconds(temp);
            temp = "";
        }
        else {
            temp += item;
        }
    }
    end = str_to_seconds(temp);
    
    // cout << seconds_to_str(start) << ' ' << seconds_to_str(end) << '\n';
    
    window[start+1]++;
    window[end+1]--;
    return;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    vector<long long> window;
    
    // 변수 초기화
    long long play_len = str_to_seconds(play_time);
    long long adv_len = str_to_seconds(adv_time);
    for (long long i = 0; i <= play_len + 1; i++) window.push_back(0);
    
    // logs 하나씩 읽어서 window 채우기
    for (string &item : logs) {
        record(window, item);
    }
    
    // 읽어가면서 최대인 지점 계산
    long long max_view = -1;
    long long max_time;
    long long cur_view = 0;
    long long sum_view = 0;
    queue<long long> que;
    que.push(0);
    for (long long i = 1; i < adv_len; i++) {
        if (window[i] < -100) cout << i << " alerted\n";
        cur_view += window[i];
        que.push(cur_view);
        sum_view += cur_view;
    }
    for (long long i = adv_len; i <= play_len; i++) {
        if (window[i] < -100) cout << i << " alerted\n";
        cur_view += window[i];
        sum_view += cur_view - que.front();
        que.push(cur_view);
        que.pop();
        if (sum_view > max_view) {
            max_time = i - adv_len;
            max_view = sum_view;
        }
    }
    
    // cout << seconds_to_str(max_view);
    // max_time을 다시 string 버전으로
    answer = seconds_to_str(max_time);
    
    return answer;
}