#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    // 변수 및 초기화
    int answer = 0;
    int row_num = board.size();
    int col_num = board[0].size();
    for (int i = 0; i < row_num; i++) board[i].push_back(0);
    board.push_back({});
    for (int j = 0; j <= col_num; j++) board[row_num].push_back(0);
    vector<vector<int>> window;
    for (int i = 0; i <= row_num; i++) {
        window.push_back({});
        for (int j = 0; j <= col_num; j++) {
            window[i].push_back(0);
        }
    }
    
    // skill 저장
    for (vector<int> item : skill) {
        int degree = item[5];
        if (item[0] == 1) degree *= -1;
        int r1 = item[1];
        int c1 = item[2];
        int r2 = item[3];
        int c2 = item[4];
        window[r1][c1] += degree;
        window[r2+1][c2+1] += degree;
        window[r1][c2+1] -= degree;
        window[r2+1][c1] -= degree;
    }
    
    // skill 집계
    for (int i = 0; i <= row_num; i++) {
        int temp = 0;
        for (int j = 0; j <= col_num; j++) {
            temp += window[i][j];
            window[i][j] = temp;
        }
    }
    for (int j = 0; j <= col_num; j++) {
        int temp = 0;
        for (int i = 0; i <= row_num; i++) {
            temp += window[i][j];
            window[i][j] = temp;
        }
    }
    
    // window[i][j]와 board[i][j]를 더해서 1 이상이면 answer++;
    for (int i = 0; i < row_num; i++) {
        for (int j = 0; j < col_num; j++) {
            if (window[i][j] + board[i][j] > 0) answer++;
        }
    }
    
    return answer;
}