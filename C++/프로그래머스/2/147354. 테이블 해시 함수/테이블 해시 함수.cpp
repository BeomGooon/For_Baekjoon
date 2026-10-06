#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct row {
    int len;
    int col;
    vector<int> data;
    
    
    row(vector<int> inp, int co) {
        len = inp.size();
        data = inp;
        col = co - 1;
    }
    
    bool operator<(const row &another) const {
        if (this->data[col] == another.data[col]) return (this->data[0] > another.data[0]);
        else return (this->data[col] < another.data[col]);
    }
};

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    // 변수 및 초기화
    int answer = 0;
    vector<row> map;
    for (vector<int> item : data) {
        map.push_back(row(item, col));
    }
    sort(map.begin(), map.end());
    
    // 로직 구현
    for (int i = row_begin; i <= row_end; i++) {
        int temp = 0;
        for (int item : map[i-1].data) {
            temp += (item % i);
        }
        answer = (answer ^ temp);
    }
    
    return answer;
}