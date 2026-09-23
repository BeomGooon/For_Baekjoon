#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int row_num = board.size();
    int col_num = board[0].size();
    for (int i = 0; i < row_num; i++) {
        for (int j = 0; j < col_num; j++) {
            if (i > 0 && j > 0 && board[i][j]){
                board[i][j] = min({board[i-1][j], board[i][j-1], board[i-1][j-1]}) + 1;
            }
            if (board[i][j] > answer) {answer = board[i][j];}
        }
    }
    return answer * answer;
}