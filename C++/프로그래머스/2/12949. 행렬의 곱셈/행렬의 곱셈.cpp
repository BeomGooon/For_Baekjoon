#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    // 행렬 크기 저장
    int row1 = arr1.size();
    int col1 = arr1[0].size();
    int row2 = col1;
    int col2 = arr2[0].size();
    
    // answer의 index 기준으로 계산
    for (int i = 0; i < row1; i++) {
        vector<int> temp_vector;
        for (int j = 0; j < col2; j++) {
            int temp = 0;
            for (int k = 0; k < col1; k++) {
                temp += (arr1[i][k] * arr2[k][j]);
            }
            temp_vector.push_back(temp);
        }
        answer.push_back(temp_vector);
        temp_vector.clear();
    }
    return answer;
}