#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> arr;

long long dp[21] = {0, 1, 2, };

long long fac(int inp) {
    if (inp < 3) return inp;
    if (dp[inp]) return dp[inp];
    else {
        long long temp = ((long long)inp) * fac(inp-1);
        dp[inp] = temp;
        return temp;
    }
}

bool touched[21] = {false, };

int find_untouched(int inp) {
    int output = 1;
    inp--;
    while (inp || touched[output]) {
        if (!touched[output]) inp--;
        output++;
    }
    touched[output] = true;
    return output;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    
    /*
    fac(20);
    for (long long item : dp) cout << item << '\n';
    return {};
    */
    
    for (int i = n-1; i > 0; i--) {
        arr.push_back(fac(i));
    }
    
    k--;
    for (int i = 0; i < n - 1; i++) {
        answer.push_back(find_untouched(1 + k / arr[i]));
        k = k % arr[i];
    }
    answer.push_back(find_untouched(1 + k));
    
    return answer;
}