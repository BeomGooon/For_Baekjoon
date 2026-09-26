#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int str_to_int(string inp) {
    int res = 0;
    for (char c : inp) {
        res = (res * 10) + (c - '0');
    }
    return res;
}

vector<int> str_to_data(string inp) { // {차량 번호, 시각(분 단위)}를 꺼내는 함수
    int hour = str_to_int(inp.substr(0, 2));
    int minute = hour * 60 + str_to_int(inp.substr(3, 2));
    int car_num = str_to_int(inp.substr(6, 4));
    vector<int> output;
    output.push_back(car_num);
    output.push_back(minute);
    return output;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<int,int> dict; // {차량 번호, 마지막 입차 시기}를 저장하는 dictionary
    unordered_map<int,int> cum_dict; // {차량 번호, 누적 분}을 저장하는 dictionary
    int last_time = 23 * 60 + 59; // 23시 59분을 분 단위로 저장(마지막까지 출차하지 못한 차 확인)
    priority_queue<int, vector<int>, greater<int>> pq; // 나중에 출력을 위한 차량 번호 pq
    
    // 기록에 대해 계산 후 cum_dict에 누적 
    for (string item : records) {
        vector<int> temp = str_to_data(item); // 현재 기록의 {차량 번호, 출/입차 시기}
        if (item[11] == 'I') { // 입차
            dict[temp[0]] = temp[1];
        }
        else { // 출차
            if (cum_dict.find(temp[0]) == cum_dict.end()) {
                cum_dict[temp[0]] = temp[1] - dict[temp[0]];
            }
            else {
                cum_dict[temp[0]] += (temp[1] - dict[temp[0]]);
            }
            dict.erase(temp[0]);
        }
        temp.clear();
    }
    
    // 아직 출차하지 못한 차들에 대해 last_time(23시 59분) 기준으로 누적 시간 계산
    for (const auto &pair : dict) {
        int car_num = pair.first;
        int in_time = pair.second;
        if (cum_dict.find(car_num) == cum_dict.end()) {
            cum_dict[car_num] = last_time - in_time;
        }
        else {
            cum_dict[car_num] += last_time - in_time;
        }
    }
    
    // 차량 번호 정렬을 위해 pq에 차량 번호 저장
    for (const auto &pair : cum_dict) {
        pq.push(pair.first);
    }
    
    // 누적 시간을 바탕으로 요금 계산
    while (!pq.empty()) {
        int car_num = pq.top();
        int cum_time = cum_dict[car_num];
        int price = fees[1] + ceil(double(max(cum_time - fees[0], 0)) / double(fees[2])) * fees[3];
        answer.push_back(price);
        pq.pop();
    }
    
    return answer;
}