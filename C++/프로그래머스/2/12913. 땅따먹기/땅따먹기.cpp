#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int row_num = land.size();
    vector<int> dp;
    dp = land[0];
    
    for (int i = 1; i < row_num; i++) {
        vector<int> temp;
        temp.push_back(max(max(dp[1], dp[2]), dp[3]) + land[i][0]);
        temp.push_back(max(max(dp[0], dp[2]), dp[3]) + land[i][1]);
        temp.push_back(max(max(dp[0], dp[1]), dp[3]) + land[i][2]);
        temp.push_back(max(max(dp[0], dp[1]), dp[2]) + land[i][3]);
        dp = temp;
    }

    answer = max(max(dp[0], dp[1]), max(dp[2], dp[3]));

    return answer;
}