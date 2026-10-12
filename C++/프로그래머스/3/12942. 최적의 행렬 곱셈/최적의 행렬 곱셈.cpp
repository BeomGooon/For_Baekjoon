#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<long long>> dp;

int solution(vector<vector<int>> matrix_sizes) {
    int N = matrix_sizes.size();
    int answer = 0;
    
    for (int i = 0; i < N; i++) {
        dp.push_back({});
        for (int j = 0; j < N; j++) dp[i].push_back(0);
    }
    
    for (int dist = 1; dist < N; dist++) {
        for (int start = 0; start + dist < N; start++) {
            int end = start + dist;
            long long output = 0x7fffffffffffffff;
            for (int k = start; k < end; k++) {
                long long temp = dp[start][k] + dp[k + 1][end] + matrix_sizes[start][0] * matrix_sizes[k][1] * matrix_sizes[end][1];
                if (temp < output) output = temp;
            }
            dp[start][end] = output;
        }
    }

    
    answer = dp[0][N-1];
    return answer;
}