#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int str_to_bit(string inp) {
    int n = inp.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += (1 << (inp[i] - 'A'));
    }
    return res;
}

string bit_to_str(int inp) {
    int k = 1;
    string res = "";
    for (int i = 0; i < 26; i++) {
        if ((inp & k) > 0) {
            res += ('A' + i);
        }
        k <<= 1;
    }
    return res;
}

vector<int> dfs(vector<int>& arr, int depth, int from) {
    int n = arr.size();
    vector<int> res;
    
    if (depth == 1) {
        for (int i = from; i < n; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
    
    for (int i = from; i < n; i++) {
        int temp = arr[i];
        vector<int> tm = dfs(arr, depth - 1, i + 1);
        int tmn = tm.size();
        for (int j = 0; j < tmn; j++) {
            res.push_back(temp|tm[j]);
        }
    }
    return res;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<int> bit_orders;
    int n = orders.size();
    vector<int> all_menus;
    int all_menu = 0;
    priority_queue<string, vector<string>, greater<string>> pq;
    
    // str을 bit로 변환 후 저장
    for (int i = 0; i < n; i++) {
        int temp = str_to_bit(orders[i]);
        bit_orders.push_back(temp);
        all_menu = all_menu | temp;
    }
    
    // 모든 단품메뉴 저장
    int bit_temp = 1;
    for (int i = 0; i < 26; i++) {
        int temp = (bit_temp & all_menu);
        if (temp > 0) {
            all_menus.push_back(temp);
        }
        bit_temp <<= 1;
    }
    
    // 단품 갯수에 따른 모든 경우의 수 vector
    int course_num = course.size();
    for (int i = 0; i < course_num; i++) {
        vector<int> output = dfs(all_menus, course[i], 0);
        int m = output.size();
        int maxnum = 0; // 시킨 손님 수
        vector<int> before_answer;
        for (int j = 0; j < m; j++) {
            int tem = output[j];
            int tem_num = 0;
            for (int k = 0; k < n; k++) {
                if ((tem & bit_orders[k]) == tem) { // 해당 메뉴를 모두 시킴
                    tem_num++;
                }
            }
            if (maxnum < tem_num) {
                maxnum = tem_num;
                before_answer.clear();
                before_answer.push_back(tem);
            }
            else if (maxnum == tem_num) {
                before_answer.push_back(tem);
            }
        }
        if (maxnum > 1) {
            int before_answer_num = before_answer.size();
            for (int j = 0; j < before_answer_num; j++) {
                pq.push(bit_to_str(before_answer[j]));
            }
        }
    }
    
    while (!pq.empty()) {
        answer.push_back(pq.top());
        pq.pop();
    }
    
    return answer;
}