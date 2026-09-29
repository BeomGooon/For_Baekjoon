#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 비어있는 공간은 blank(' ')으로 채움

// 빈칸 없애서 아래로 붙이는 함수
void fill_2d(vector<string> &inp) {
    // 사이즈 저장
    int row_num = inp.size();
    int col_num = inp[0].size();
    
    // 아래서부터 위로, 왼쪽에서 오른쪽으로 탐색
    for (int i = row_num - 1; i >= 0; i--) {
        for (int j = 0; j < col_num; j++) {
            // 만약 빈칸을 찾으면 위에 다른 블럭 있는지 확인. 있으면 문자 교환. 없으면 그대로 유지
            if (inp[i][j] == ' ') {
                for (int k = i - 1; k >= 0; k--) {
                    // 위로 올라가다 빈칸이 아닌 블럭 발견
                    if (inp[k][j] != ' ') {
                        inp[i][j] = inp[k][j];
                        inp[k][j] = ' ';
                        break;
                    }
                }
            }
        }
    }
}

// 2x2 칸 지우는 함수
void delete_2d(vector<string> &inp) {
    // 사이즈 저장
    int row_num = inp.size();
    int col_num = inp[0].size();
    
    // 따로 미리 저장
    vector<string> copy_inp = inp;
    
    long long prev_ind = 0;
    long long cur_ind = 0;
    long long temp_ind = 0x01;
    char cur_char;
    char prev_char = copy_inp[0][0];
    for (int j = 1; j < col_num; j++) {
        cur_char = copy_inp[0][j];
        if (prev_char == cur_char) {
            cur_ind = (cur_ind | temp_ind);
        }
        prev_char = cur_char;
        temp_ind <<= 1;
    }
    prev_ind = cur_ind;
    cur_ind = 0;
    temp_ind = 0x01;
    for (int i = 1; i < row_num; i++) {
        prev_char = copy_inp[i][0];
        for (int j = 1; j < col_num; j++) {
            cur_char = copy_inp[i][j];
            // 바로 이전 동일한 캐릭터 블록 존재
            if (prev_char == cur_char) {
                cur_ind = (cur_ind | temp_ind);
                // 바로 위에서도 동일한 곳에 동일한 캐릭터 블록 존재
                if (copy_inp[i-1][j] == copy_inp[i][j] && (cur_ind & temp_ind) == (prev_ind & temp_ind)) {
                    inp[i-1][j-1] = ' ';
                    inp[i-1][j] = ' ';
                    inp[i][j-1] = ' ';
                    inp[i][j] = ' ';
                }
            }
            prev_char = cur_char;
            temp_ind <<= 1;
        }
        prev_ind = cur_ind;
        cur_ind = 0;
        temp_ind = 0x01;
    }
}

// board의 변화를 발견하는 함수 (true: 변화 O, false: 변화 X)
bool changed(vector<string> &before, vector<string> &after) {
    // 사이즈 저장
    int row_num = before.size();
    int col_num = before[0].size();
    
    // 변화 확인
    for (int i = 0; i < row_num; i++) {
        if (before[i] != after[i]) return true;
    }
    return false;
}

// step 함수
void step(vector<string> &inp) {
    // 2x2 그리드 제거하는 함수 실행
    delete_2d(inp);
    // 블록을 아래로 채우는 함수 실행
    fill_2d(inp);
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<string> before = board;
    step(board);
    while (changed(before, board)) {
        before = board;
        step(board);
    }
    
    // 빈 칸의 갯수 찾기
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == ' ') answer++;
        }
    }
    
    return answer;
}