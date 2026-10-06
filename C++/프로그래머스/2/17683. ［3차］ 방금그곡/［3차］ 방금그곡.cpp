#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<string, int> note = {
    {"C", 0},
    {"C#", 1},
    {"D", 2},
    {"D#", 3},
    {"E", 4},
    {"F", 5},
    {"F#", 6},
    {"G", 7},
    {"G#", 8},
    {"A", 9},
    {"A#", 10},
    {"B", 11}
};

struct song {
    int start_time;
    int end_time;
    int len;
    int original_len;
    string name;
    vector<int> melody;
    
    song(string inp) {
        int start = 0;
        int end = 0;
        start += 600 * (inp[0] - '0');
        start += 60 * (inp[1] - '0');
        start += 10 * (inp[3] - '0');
        start += (inp[4] - '0');
        end += 600 * (inp[6] - '0');
        end += 60 * (inp[7] - '0');
        end += 10 * (inp[9] - '0');
        end += (inp[10] - '0');
        start_time = start;
        end_time = end;
        len = end - start;
        
        string name_and_melody = inp.substr(12, inp.size()-12);
        name = "";
        string temp_melody;
        for (int i = 0; i < name_and_melody.size(); i++) {
            char item = name_and_melody[i];
            if (item == ',') {
                temp_melody = name_and_melody.substr(i + 1, name_and_melody.size() - (i + 1));
                break;
            }
            else name += item;
        }
        int mel_cycle = temp_melody.size();
        original_len = mel_cycle;
        int temp_cycle = len;
        for (int i = 0; i < temp_cycle; i++) {
            int ind = i % mel_cycle;
            string tem = "";
            tem += temp_melody[ind];
            if (ind != mel_cycle - 1 && temp_melody[ind + 1] == '#') { tem += '#'; i++; temp_cycle++; }
            melody.push_back(note[tem]);
        }
    }
    
    bool operator<(const song &another) const {
        return (this->start_time > another.start_time);
    }
    
    bool match(const vector<int> &inp) const {
        int target_len = inp.size();
        for (int i = 0; i < original_len; i++) {
            int cur_ind = 0;
            while (cur_ind < target_len && i + cur_ind < len && inp[cur_ind] == melody[i + cur_ind]) cur_ind++;
            if (target_len == cur_ind) return true;
        }
        return false;
    }
};

struct just_name {
    string name;
    int len;
    int start_time;
    
    just_name(string n, int l, int st) {
        name = n;
        len = l;
        start_time = st;
    }
    
    bool operator<(const just_name &another) const {
        if (this->len == another.len) return (this->start_time > another.start_time);
        else return (this->len < another.len);
    }
};

string solution(string m, vector<string> musicinfos) {
    // 변수 및 초기화
    string answer = "";
    priority_queue<song> pq;
    vector<int> target;
    for (string item : musicinfos) {
        pq.push(song(item));
    }
    
    /*
    while (!pq.empty()) {
        song item = pq.top();
        pq.pop();
        cout << item.name << '\n';
        for (int temp : item.melody) {
            cout << temp << '\n';
        }
        cout << '\n';
    }
    return "";
    */
    
    // target 채우기
    for (int i = 0; i < m.size(); i++) {
        string temp = "";
        temp += m[i];
        if (i < m.size() - 1 && m[i + 1] == '#') {temp += '#'; i++;}
        target.push_back(note[temp]);
    }
    
    // pq에서 하나씩 뽑으면서 확인
    priority_queue<just_name> pq2;
    while (!pq.empty()) {
        song temp = pq.top();
        pq.pop();
        if (temp.match(target)) pq2.push(just_name(temp.name, temp.len, temp.start_time));
    }
    
    if (pq2.empty()) return "(None)";
    answer = pq2.top().name;
    
    return answer;
}