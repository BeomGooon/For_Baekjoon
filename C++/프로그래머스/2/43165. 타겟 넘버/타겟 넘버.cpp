#include <string>
#include <vector>
#include <stack>

using namespace std;

int n, target;
vector<int> arr;

int dfs(int depth, int cur_sum) { // depth(index)와 현재까지의 sum을 넣고, 그 뒤의 모든 경우의 수를 return
    int res = 0;
    if (depth == n) {
        return (cur_sum == target);
    }
    return (dfs(depth+1, cur_sum+arr[depth]) + dfs(depth+1, cur_sum-arr[depth]));
}

int solution(vector<int> numbers, int tar) {
    int answer = 0;
    n = numbers.size();
    target = tar;
    arr = numbers;
    answer = dfs(0, 0);
    return answer;
}