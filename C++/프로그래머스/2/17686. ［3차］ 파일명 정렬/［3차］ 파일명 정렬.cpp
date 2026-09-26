#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cctype>

using namespace std;

// 단순 HEAD를 string 순서로 넣어도 되는가?

bool compare(pair<vector<string>, vector<int>> a, pair<vector<string>, vector<int>> b) {
    if (a.first[1] != b.first[1]) return (a.first[1] < b.first[1]);
    else {
        if (a.second[0] != b.second[0]) return (a.second[0] < b.second[0]);
        else {
            return (a.second[1] < b.second[1]);
        }
    }
}

int str_to_int(string inp) {
    int res = 0;
    for (char c : inp) {
        res = (res * 10) + (c - '0');
    }
    return res;
}

struct ext_file {
    string file_name;
    string head;
    int num;
    int index;
    
    bool operator< (const ext_file &other) const {
        if (this->head != other.head) return (this->head > other.head);
        else {
            if (this->num != other.num) return (this->num > other.num);
            else return (this->index > other.index);
        }
    }
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    priority_queue<ext_file> pq; // {{파일명, head}, {num, 인덱스}} 순서대로 저장
    
    // HEAD와 NUMBER을 포함한 ext_files 채우기
    int index = 0;
    ext_file cur;
    for (string item : files) {
        string head = "";
        string num = "";
        bool head_flag = true; // true이면 head를 채울 차례, false면 num을 채울 차례
        for (char c : item) {
            if (head_flag) {
                if (c >= '0' && c <= '9') { // 처음으로 숫자를 만남
                    num += c;
                    head_flag = false;
                }
                else { // head 계속 채움
                    head += tolower(c);
                }
            }
            else {
                if (c >= '0' && c <= '9') {
                    num += c;
                }
                else break;
            }
        }
        cur.file_name = item;
        cur.head = head;
        cur.num = str_to_int(num);
        cur.index = index;
        pq.push(cur);
        index++;
    }
    
    // 하나씩 꺼내며 출력
    ext_file temp;
    while (!pq.empty()) {
        temp = pq.top();
        answer.push_back(temp.file_name);
        pq.pop();
    }
    
    return answer;
}