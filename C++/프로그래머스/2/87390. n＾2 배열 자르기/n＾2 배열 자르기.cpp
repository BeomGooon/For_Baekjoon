#include <string>
#include <vector>

using namespace std;

// 특정 index를 n으로 나눠서 몫 => 행(i), 나머지 => 열(j)
// i행의 특징: j = 0부터 j = i까지 (i+1)로 채워짐 
// 그 후 j + 1로 채움
// => max(i + 1, j + 1) {for j = 0 ~ j = n - 1}
// left와 right에 대해 몫과 나머지를 구하고
// left, 중간, right에 대해 vector에 추가

void cal(vector<int> &answer, int row, int col_from, int col_to) {
    for (int j = col_from; j < col_to + 1; j++) {
        answer.push_back(max(row + 1, j + 1));
    }
    return;
}

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    long long left_row = left / n;
    long long left_col = left % n;
    long long right_row = right / n;
    long long right_col = right % n;
    
    if (left_row < right_row) {
        cal(answer, left_row, left_col, n-1);
        for (int i = left_row+1; i < right_row; i++) {
            cal(answer, i, 0, n-1);
        }
        cal(answer, right_row, 0, right_col);
    }
    else {
        cal(answer, left_row, left_col, right_col);
    }
    return answer;
}