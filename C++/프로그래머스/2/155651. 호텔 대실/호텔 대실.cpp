#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 예약 객체
struct appointment {
    string start;
    string end;
    
    appointment(string st, string en) {
        start = st;
        end = en;
    }
    
    // 이건 pq용. 끝나는 시간 기준으로 계산
    bool operator<(const appointment &another) const { 
        return (this->end > another.end);
    }
};

bool compare(appointment &one, appointment &another) {
    if (one.start == another.start) return (one.end < another.end);
    else return (one.start < another.start);
}

// 10분 추가 함수
string add_10_min(string &inp) {
    string output = "";
    int minutes = 0;
    minutes += 600 * (inp[0] - '0');
    minutes += 60 * (inp[1] - '0');
    minutes += 10 * (inp[3] - '0');
    minutes += (inp[4] - '0');
    minutes += 10;
    
    output += (char(minutes / 600 + '0'));
    minutes = minutes % 600;
    output += (char(minutes / 60 + '0'));
    minutes = minutes % 60;
    output += ':';
    output += (char(minutes / 10 + '0'));
    minutes = minutes % 10;
    output += (char(minutes + '0'));
    return output;
}

int solution(vector<vector<string>> book_time) {
    // 변수 및 초기화
    int answer = 0;
    vector<appointment> app_list;
    priority_queue<appointment> pq;
    for (vector<string> times : book_time) {
        app_list.push_back(appointment(times[0], add_10_min(times[1])));
    }
    
    // 정렬
    sort(app_list.begin(), app_list.end(), compare);
    
    /* 디버깅용 확인
    for (appointment item : app_list) {
        cout << item.start << ' ' << item.end << '\n';
    }
    */
    
    // 하나씩 꺼내며 최대 개수 확인
    for (appointment item : app_list) {
        string cur_time = item.start;
        pq.push(item);
        
        // 혹시 이미 끝난 거 있으면 확인
        while (cur_time >= pq.top().end) {
            pq.pop();
        }
        
        // pq 개수 확인 및 업데이트
        if (answer < pq.size()) answer = pq.size();
    }
    
    return answer;
}