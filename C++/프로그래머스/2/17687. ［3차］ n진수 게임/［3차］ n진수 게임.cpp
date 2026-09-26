#include <string>
#include <vector>
#include <iostream>

using namespace std;

char degrees[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void next_vec(vector<int> &inp, int max_degree) { // max_degree는 n진법의 n을 의미 (=> n-1까지 저장 가능)
    int n = inp.size();
    for (int i = n - 1; i >= 0; i--) {
        if (inp[i] == max_degree - 1) {
            inp[i] = 0;
        }
        else {
            inp[i]++;
            break;
        }
    }
    if (inp[0] == 0) { // 자리수 추가
        inp.clear();
        inp.push_back(1);
        for (int i = 0; i < n; i++) inp.push_back(0);
    }
    return;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    vector<int> cur_num;
    cur_num.push_back(0);
    int person_index = 1;
    int num_index = 0;
    int tube_turn = p;
    int passed = 0; // answer에 char을 추가할 때 마다 + 1
    int cur_size = 1;
    while (passed < t) {
        // 튜브의 차례일 때 answer에 추가
        if (person_index == tube_turn) {
            answer += degrees[cur_num[num_index]];
            tube_turn += m;
            passed++;
        }
        
        // person_index 업데이트
        person_index++;
        
        // num_index 업데이트
        if (num_index == cur_size - 1) {
            next_vec(cur_num, n);
            cur_size = cur_num.size();
            num_index = 0;
        }
        else num_index++;
    }
    
    return answer;
}